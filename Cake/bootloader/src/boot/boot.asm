[bits 16]

org 0x7c00

boot:
    cli
    ; save boot drive number
    mov [boot_drv], dl
    ; reset register
    xor ax, ax
    mov ds, ax
    mov es, ax
    mov ss, ax

    mov bp, 0x9000
    mov sp, bp

    call init_screen
    call seta20_1
    call e820
    call load_loader
    call init_protected
    jmp CODE_SEG:enter_protected
    jmp $

init_screen:
    mov ax, 0x0600
    mov bh, 0x0f
    mov cx, 0x0000
    mov dx, 0x184f
    int 0x10

    mov ah, 0x02
    mov bh, 0x00
    mov dx, 0x0000
    int 0x10
    ret

seta20_1:
    in al, 0x64
    test al, 0x02
    jnz seta20_1
    mov al, 0xd1
    out 0x64, al
seta20_2:
    in al, 0x64
    test al, 0x02
    jnz seta20_2
    mov al, 0xdf
    out 0x60, al
seta20_3:
    in al, 0x92
    test al, 0x02
    jnz seta20_4
    or al, 0x02
    and al, 0xfe
    out 0x92, al
seta20_4:
    ret

e820:
    mov di, 0x9000
    xor ebx, ebx
    xor bp, bp
    mov edx, 0x0534d4150
    mov eax, 0xe820
    mov dword [es:di + 20], 0x1
    mov ecx, 24
    int 0x15
    jc .failed
    mov edx, 0x0534d4150
    cmp eax, edx
    jne .failed
    test ebx, ebx
    je .failed
    jmp .jmpin
.e820lp:
    mov eax, 0xe820
    mov dword [es:di + 20], 0x1
    mov ecx, 24
    int 0x15
    jc .e820f
    mov edx, 0x0534d4150
.jmpin:
    jcxz .skipent
    cmp cl, 20
    jbe .notext
    test byte [es:di + 20], 0x1
    je .skipent
.notext:
    mov ecx, [es:di + 8]
    or ecx, [es:di + 12]
    jz .skipent
    inc bp
    add di, 24
.skipent:
    test ebx, ebx
    jne .e820lp
.e820f:
    ; mov [mmap_ent], bp
    clc
    ret
.failed:
    stc
    ret

load_loader:
    mov ax, 0x0203
    mov cx, 0x0002
    mov dh, 0x00
    mov dl, [boot_drv]
    mov bx, loader_off
    int 0x13
    jc .error
    ret
.error:
    jmp $

init_protected:
    lgdt [gdt_des]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    ret

[bits 32]
enter_protected:
    mov eax, DATA_SEG
    mov ds, eax
    mov es, eax
    mov fs, eax
    mov gs, eax
    mov ss, eax

    mov ebp, 0x9000
    mov esp, ebp

    jmp loader_off

    jmp $

loader_off equ 0x1000
boot_drv: db 0
; mmap_ent: db 0

gdt_start:
gdt_null:
    dq 0x00
gdt_code:
    dq 0x00cf9a000000ffff
gdt_data:
    dq 0x00cf92000000ffff
gdt_end:
gdt_des:
    dw gdt_end - gdt_start - 1
    dd gdt_start
CODE_SEG equ gdt_code - gdt_start
DATA_SEG equ gdt_data - gdt_start

times 510 - ($ - $$) db 0
dw 0xaa55