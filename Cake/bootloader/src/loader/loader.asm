global loader

[bits 32]

loader:
    call load_kernel
    jmp entry_off
    jmp $

load_kernel:
    ; disk offset
    ; sectors count
    ; memory offset
    mov eax, 0x4
    mov ecx, 0x1
    mov edi, kernel_off
    call read_segment
    call check_elf

    ; get program entry address
    mov eax, [kernel_off + 0x60]
    shr eax, 8
    mov dl, 2
    div dl
    xor ah, ah
    add al, 1
    ; get elf length
    mov ecx, eax
    mov eax, 0xc
    mov edi, kernel_off
    call read_segment

    mov eax, 0xc
    mov ecx, 0x21
    mov edi, kernel_off
    call read_segment
    ret
.n:
    jmp $

read_segment:
    call read_sector
    inc eax
    add edi, 0x200
    loop read_segment
    ret

read_sector:
    push eax
    push ebx
    push ecx
    push edx
    push edi

    mov ebx, eax

    mov edx, 0x01f6
    shr eax, 24
    or al, 0xe0
    out dx, al

    ; count
    mov edx, 0x01f2
    mov al, 0x1
    out dx, al

    mov edx, 0x01f3
    mov eax, ebx
    out dx, al

    mov edx, 0x01f4
    mov eax, ebx
    shr eax, 8
    out dx, al

    mov edx, 0x01f5
    mov eax, ebx
    shr eax, 16
    out dx, al
    ; read commond
    mov edx, 0x01f7
    mov al, 0x20
    out dx, al
.still_going:
    in al, dx
    test al, 8
    jz .still_going

    mov eax, 256
    xor bx, bx
    mov bl, 0x1
    mul bx
    mov ecx, eax
    mov edx, 0x1f0
    rep insw

    pop edi
    pop edx
    pop ecx
    pop ebx
    pop eax
    ret

check_elf:
    mov eax, [kernel_off]
    cmp eax, 0x464c457f
    jne .no_elf
    ret
.no_elf:
    mov eax, 0xb8000
    mov byte [eax], 0x0f
    mov byte [eax], 'n'
    jmp $

entry_off equ 0xff000
kernel_off equ 0x100000
