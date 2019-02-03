bits 32

mov edx, 0xb8000
mov ax, 0x0f0f
mov [edx], ax
hlt
jmp $

times 1024 - ($ - $$) db 0
