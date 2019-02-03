bits 16

org 0x7c00

start:
    ;save boot driver number
    mov [boot_drv], dl
    ;init segement register
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    
    call clear_screen
    mov cx, msg1_len
    mov bp, msg1
    call print_string
    
    call new_line
    mov cx, msg2_len
    mov bp, msg2
    call print_string
    
    call load_loader
    
    ;ready to go to protected mode
    cli
    lgdt [gdt_des]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:init_protected
    
    hlt
    jmp $
    
clear_screen:
    ;use int 0x10 to clear sreen and reset cursor
    
    mov al, 0x00
    call scroll_screen
    call reset_cursor
    ret
    
print_string:
    ;use int 0x10 to print string in screen
    ;to use that, you shold set cx, bp and call update cursor to set where put character
    ;cx is the count of string
    ;bp is the index of string
    
    ;bx = 0x0007, page number is 0, character attribte is 0x07
    ;ah = 0x13, interrupt attribte is print string
    ;al = 0x01, screen mode is text mode
    mov bx, 0x0007
    mov ax, 0x1301
    int 0x10
    ret
    
new_line:
    ;set cursor to next line

    mov al, 0x01
    call scroll_screen
    call reset_cursor
    ret

scroll_screen:
    ;before call that, set al
    ;al = 0, clear all
    ;al = n, scroll down n number
    
    ;ah = 0x07, move screen down
    ;cx = 0x0000, start position is (0, 0)
    ;dx = 0x30a0, end position is (25, 80)
    ;bh = 0x07, character attribte is 0x07
    mov ah, 0x07
    mov cx, 0x0000
    mov dx, 0x30a0
    mov bh, 0x07
    int 0x10
    ret
    
reset_cursor:
    ;reset cursor position at (0, 0)
    
    ;ah = 0x02, set cursor position
    ;bh = 0x00, page number is 0
    ;dx = 0x00, cursor position is (0, 0)
    mov ah, 0x02
    mov bh, 0x00
    mov dx, 0x0000
    int 0x10
    ret
    
load_loader:
    ;read loader at 0x10000
    
    ;ah = 0x02, interrupt attribute, read disk
    ;al = 0x02, the number of reading sector
    ;ch = 0x00, cylinder number
    ;cl = 0x02, sector number
    ;dh = 0x00, head number
    ;dl, driver number
    mov ax, 0x0202
    mov cx, 0x0002
    mov dh, 0x00
    mov dl, [boot_drv]
    mov bx, loader_off
    int 0x13
    
    jc .error
    
    call new_line
    mov cx, msg3_len
    mov bp, msg3
    call print_string
    ret
.error:
    call new_line
    mov cx, err1_len
    mov bp, err1
    call print_string
    hlt
    jmp $
    
bits 32

init_protected:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    call loader_off
    
    hlt
    jmp $

gdt_start:
gdt_null:
    ;dummy
    dq 0x00
gdt_code:
    ;limit
    ;base address
    ;permission
    ;granularity
    dw 0xffff
    dw 0x0000
    dw 0x9a00
    dw 0x00cf
gdt_data:
    dw 0xffff
    dw 0x0000
    dw 0x9200
    dw 0x00cf
gdt_end:
gdt_des:
    dw gdt_end - gdt_start - 1
    dd gdt_start
    
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
    
boot_drv: db 0
loader_off equ 0x1000

msg1: db "Start loading..."
msg1_len equ $ - msg1

msg2: db "Load loader..."
msg2_len equ $ - msg2

msg3: db "Load loader success."
msg3_len equ $ - msg3

err1: db "Read disk error..."
err1_len equ $ - err1

times 510 - ($ - $$) db 0
dw 0xaa55
