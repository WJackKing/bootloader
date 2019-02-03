[bits 64]

global load_idt
extern int_handler

load_idt:
    mov edx, [esp + 4]
    lidt [edx]
    sti
    ret

%macro int_code 1
global int%1
int%1:
    cli
    push %1
    jmp int_service
%endmacro

%macro int_nocode 1
global int%1
int%1:
    cli
    push 0
    push %1
    jmp int_service
%endmacro

int_service:
    push rdi
    push rsi
    push rdx
    push rcx
    push rax
    push r8
    push r9
    push r10
    push r11
    call int_handler
    pop r11
    pop r10
    pop r9
    pop r8
    pop rax
    pop rcx
    pop rdx
    pop rsi
    pop rdi
    iretq

int_nocode 0
int_nocode 1
int_nocode 2
int_nocode 3
int_nocode 4
int_nocode 5
int_nocode 6
int_nocode 7
int_code 8
int_nocode 9
int_code 10
int_code 11
int_code 12
int_code 13
int_code 14
int_nocode 15
