;boot code, this is the first code that computer call
;bios read it in memory at 0x7c00
;in this code, i load loader in 0x1000

[bits 16]

org 0x7c00

boot:
    ;save boot driver number
    mov [boot_drv], dl
    ;init stack register and segement register
    mov bp, 0x9000
    mov sp, bp
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax

    ;load loader in 0x1000, next, call it
    call load_loader
    call loader_off
    
    hlt
    jmp $
    
load_loader:
    ;read loader at 0x1000
    
    ;ah, interrupt attribute, read disk
    ;al, the number of reading sector, in there we need to read more
    ;ch, cylinder number
    ;cl, sector number
    ;dh, head number
    ;dl, driver number
    mov ax, 0x0233
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

boot_drv: db 0
loader_off equ 0x1000

;make it bootable
times 510 - ($ - $$) db 0
dw 0xaa55
