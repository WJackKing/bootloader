;readed by boot
;i think it will more perfect to go into long mode
[bits 32]

global loader

section .text
loader:

    mov byte [0xa0000], 00011000b
    mov byte [0xa0050], 00111100b
    mov byte [0xa00a0], 01100110b
    mov byte [0xa00f0], 01100110b
    mov byte [0xa0140], 01111110b
    mov byte [0xa0190], 01100110b
    mov byte [0xa01e0], 01100110b
    mov byte [0xa0230], 00000000b
    
    mov byte [0xa0001], 01111100b
    mov byte [0xa0051], 01100110b
    mov byte [0xa00a1], 01100110b
    mov byte [0xa00f1], 01111100b
    mov byte [0xa0141], 01100110b
    mov byte [0xa0191], 01100110b
    mov byte [0xa01e1], 01111100b
    mov byte [0xa0231], 00000000b
    
    mov byte [0xa0002], 00111100b
    mov byte [0xa0052], 01100110b
    mov byte [0xa00a2], 01100110b
    mov byte [0xa00f2], 01100000b
    mov byte [0xa0142], 01100110b
    mov byte [0xa0192], 01100110b
    mov byte [0xa01e2], 00111100b
    mov byte [0xa0232], 00000000b
    
    mov byte [0xa0003], 01111100b
    mov byte [0xa0053], 01100110b
    mov byte [0xa00a3], 01100110b
    mov byte [0xa00f3], 01100110b
    mov byte [0xa0143], 01100110b
    mov byte [0xa0193], 01100110b
    mov byte [0xa01e3], 01111100b
    mov byte [0xa0233], 00000000b
    
    hlt
    jmp $

section .data
times 1024 - ($ - $$) db 0
