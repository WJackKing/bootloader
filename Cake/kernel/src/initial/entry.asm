global entry
global pml4
extern initial

section .text

[bits 32]

entry:
    call check_cpuid
    call check_long
    call init_page
    call init_long
    jmp CODE64_SEG:enter_long
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
    mov eax, pt_1
    or eax, 11b
    mov [pd], eax

    mov eax, pt_2
    or eax, 11b
    mov [pd + 8], eax

    ;initiate some data to start loop
    mov eax, 11b
    mov ecx, 0
.map_pt_1:
    mov [pt_1 + ecx * 8], eax
    add eax, 0x1000
    inc ecx
    cmp eax, 0x200000
    jb .map_pt_1
    mov ecx, 0
.map_pt_2:
    mov [pt_2 + ecx * 8], eax
    add eax, 0x1000
    inc ecx
    cmp eax, 0x400000
    jb .map_pt_2
    mov ecx, 0
.map_pt_3:
    mov [pt_3 + ecx * 8], eax
    add eax, 0x1000
    inc ecx
    cmp eax, 0x600000
    jb .map_pt_3
    mov ecx, 0
.map_pt_4:
    mov [pt_4 + ecx * 8], eax
    add eax, 0x1000
    inc ecx
    cmp eax, 0x800000
    jb .map_pt_4
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
    mov rax, DATA64_SEG
    mov ds, rax
    mov es, rax
    mov fs, rax
    mov gs, rax
    mov ss, rax

    mov ebp, stack_top
    mov esp, ebp

    jmp initial

    jmp $

section .rodata
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
pt_1:
    resb 4096
pt_2:
    resb 4096
pt_3:
    resb 4096
pt_4:
    resb 4096
stack_bottom:
    resb 4096 * 4
stack_top:
