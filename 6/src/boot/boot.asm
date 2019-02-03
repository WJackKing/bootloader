;boot code, this is the first code that computer call
;bios read it in memory at 0x7c00
;in this code, i load loader in 0x1000, and switch to protected mode

[bits 16]

org 0x7c00

boot:
    ;save boot driver number
    mov [boot_drv], dl
    ;init segement register
    mov bp, 0x9000
    mov sp, bp
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax
    
    call clear_screen
    call load_loader
    
    ;ready to go to protected mode
    ;close interrupt
    ;load gdt
    ;switch to protected mode
    call init_protected
    
    hlt
    jmp $
    
clear_screen:
    mov ah, 0x00
    mov al, 0x11
    int 0x10
    ret
    
load_loader:
    ;read loader at 0x1000
    
    ;ah = 0x02, interrupt attribute, read disk
    ;al = 0x11, the number of reading sector, in there we need to read more
    ;ch = 0x00, cylinder number
    ;cl = 0x02, sector number
    ;dh = 0x00, head number
    ;dl, driver number
    mov ax, 0x0232
    mov cx, 0x0002
    mov dh, 0x00
    mov dl, [boot_drv]
    mov bx, loader_off
    int 0x13
    
    jc .error
    ret
.error:
    hlt
    jmp $
    
init_protected:
    cli
    lgdt [gdt_des]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    jmp CODE_SEG:enter_protected
    ret
    
[bits 32]

enter_protected:
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    mov ebp, 0x90000
    mov esp, ebp

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
    db 0x00
    db 10011010b
    db 11001111b
    db 0x00
gdt_data:
    dw 0xffff
    dw 0x0000
    db 0x00
    db 10010010b
    db 11001111b
    db 0x00
gdt_end:
gdt_des:
    dw gdt_end - gdt_start - 1
    dd gdt_start
    
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start
    
boot_drv: db 0
loader_off equ 0x1000

times 510 - ($ - $$) db 0
dw 0xaa55
