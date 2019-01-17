#include <init/kmain.h>

extern void kmain() {
    show_1(0, 0);
    show_a(0, 1);
    show_b(0, 2);
    while(1);
}

void show_1(unsigned int r, unsigned int c) {
    r *= 0x280;
    unsigned char* video = (unsigned char*)0xa0000;
    *(video + r + c + 0x000) = 0x38;
    *(video + r + c + 0x050) = 0x78;
    *(video + r + c + 0x0a0) = 0x18;
    *(video + r + c + 0x0f0) = 0x18;
    *(video + r + c + 0x140) = 0x18;
    *(video + r + c + 0x190) = 0x18;
    *(video + r + c + 0x1e0) = 0x7e;
    *(video + r + c + 0x230) = 0x00;
}

void show_a(unsigned int r, unsigned int c) {
    r *= 0x280;
    unsigned char* video = (unsigned char*)0xa0000;
    *(video + r + c + 0x000) = 0x18;
    *(video + r + c + 0x050) = 0x3c;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x66;
    *(video + r + c + 0x140) = 0x7e;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x66;
    *(video + r + c + 0x230) = 0x00;
}

void show_b(unsigned int r, unsigned int c) {
    r *= 0x280;
    unsigned char* video = (unsigned char*)0xa0000;
    *(video + r + c + 0x000) = 0x7c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x7c;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x7c;
    *(video + r + c + 0x230) = 0x00;
}
