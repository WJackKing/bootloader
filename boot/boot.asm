bits 16

org 0x7c00

start:
    xor ax, ax
    mov ds, ax
    mov gs, ax
    mov fs, ax
    mov gs, ax
    
    call clear_screen
    mov cx, msg1_len
    mov bp, msg1
    call print_string
    
    call new_line
    mov cx, msg2_len
    mov bp, msg2
    call print_string
    
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
    
msg1: db "Start loading..."
msg1_len equ $ - msg1
msg2: db "Read system..."
msg2_len equ $ - msg2

times 510 - ($ - $$) db 0
dw 0xaa55
