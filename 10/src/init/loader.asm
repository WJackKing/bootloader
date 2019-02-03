;readed by boot
;i think it will more perfect to go into long mode

;used by linker, called by boot.asm
global loader
;c function
extern kmain

section .text

[bits 16]
loader:
    ;set video mode and initiate protected mode
    call set_screen
    call init_protected
    jmp CODE_SEG:enter_protected

set_screen:
    ; vbe mode
    mov ax, 0x4f02
    mov bx, 0x4118
    int 0x10
    cmp ax, 0x4f00
    jne .success
    mov ax, 0x0011
    int 0x10
    ret
.success:
    ret

init_protected:
    cli
    lgdt [gdt_des]
    mov eax, cr0
    or eax, 0x1
    mov cr0, eax
    ret

[bits 32]
enter_protected:
    ;init segment register
    mov ax, DATA_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax
    
    mov ebp, 0x90000
    mov esp, ebp

    ;make sure you cpu support cpu
    call check_cpuid
    call check_long
    call init_page
    call init_long
    jmp CODE64_SEG:enter_long
    hlt
    jmp $
    
check_cpuid:
    pushfd
    pop eax
    mov ecx, eax
    xor eax, 1 << 21
    push eax
    popfd
    pushfd
    pop eax
    push ecx
    popfd
    cmp eax, ecx
    je .no_cpuid
    ret
.no_cpuid:
    hlt
    jmp $
    
check_long:
    mov eax, 0x80000000
    cpuid
    cmp eax, 0x80000001
    jb .no_long
    
    mov eax, 0x80000001
    cpuid
    test edx, 1 << 29
    jz .no_long
    ret
.no_long:
    hlt
    jmp $

init_page:
    ;build page map level 4
    mov eax, pdpt
    or eax, 11b
    mov [pml4], eax

    ;build page directory pointer table
    mov eax, pd
    or eax, 11b
    mov [pdpt], eax

    ;build page directory
    mov eax, pt
    or eax, 11b
    mov [pd], eax

    ;initiate some data to start loop
    mov eax, 11b
    mov ecx, 0
.map_pt:
    mov [pt + ecx * 8], eax
    add eax, 0x1000
    inc ecx
    cmp eax, 0x200000
    jb .map_pt
    ret

init_long:
    ;enable pae-flag in cr4
    mov eax, cr4
    or eax, 1 << 5
    mov cr4, eax

    ;load pml4 to cr3
    mov eax, pml4
    mov cr3, eax

    ;set long mode
    mov ecx, 0xc0000080
    rdmsr

    or eax, 0x00000100
    wrmsr
.enable_page:
    mov ebx, cr0
    or ebx, 0x80000001
    mov cr0, ebx
.load_gdt64:
    lgdt [gdt64_des]
    ret

[bits 64]
enter_long:
    mov ax, DATA64_SEG
    mov ds, ax
    mov es, ax
    mov fs, ax
    mov gs, ax
    mov ss, ax

    mov ebp, stack_top
    mov esp, ebp

    call kmain

    hlt
    jmp $

section .rodata
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

gdt64_start:
gdt64_null:
    dq 0x00
gdt64_code:
    dq 0x00209A0000000000
gdt64_data:
    dq 0x0000920000000000
gdt64_end:
gdt64_des:
    dw gdt64_end - gdt64_start - 1
    dq gdt64_start

CODE64_SEG equ gdt64_code - gdt64_start
DATA64_SEG equ gdt64_data - gdt64_start

section .bss
align 4096
pml4:
    resb 4096
pdpt:
    resb 4096
pd:
    resb 4096
pt:
    resb 4096
stack_bottom:
    resb 65536
stack_top:

section .data
db 0
