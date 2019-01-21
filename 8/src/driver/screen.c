#include <driver/screen.h>


void show_space(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x00;
    *(video + r + c + 0x050) = 0x00;
    *(video + r + c + 0x0a0) = 0x00;
    *(video + r + c + 0x0f0) = 0x00;
    *(video + r + c + 0x140) = 0x00;
    *(video + r + c + 0x190) = 0x00;
    *(video + r + c + 0x1e0) = 0x00;
    *(video + r + c + 0x230) = 0x00;
}

void show_1(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x38;
    *(video + r + c + 0x050) = 0x78;
    *(video + r + c + 0x0a0) = 0x18;
    *(video + r + c + 0x0f0) = 0x18;
    *(video + r + c + 0x140) = 0x18;
    *(video + r + c + 0x190) = 0x18;
    *(video + r + c + 0x1e0) = 0x7e;
    *(video + r + c + 0x230) = 0x00;
}

void show_2(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x06;
    *(video + r + c + 0x0f0) = 0x0c;
    *(video + r + c + 0x140) = 0x30;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x7e;
    *(video + r + c + 0x230) = 0x00;
}

void show_3(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x06;
    *(video + r + c + 0x0f0) = 0x1c;
    *(video + r + c + 0x140) = 0x06;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_4(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x0c;
    *(video + r + c + 0x050) = 0x1c;
    *(video + r + c + 0x0a0) = 0x3c;
    *(video + r + c + 0x0f0) = 0x6c;
    *(video + r + c + 0x140) = 0x7e;
    *(video + r + c + 0x190) = 0x0c;
    *(video + r + c + 0x1e0) = 0x0c;
    *(video + r + c + 0x230) = 0x00;
}

void show_5(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x7e;
    *(video + r + c + 0x050) = 0x60;
    *(video + r + c + 0x0a0) = 0x60;
    *(video + r + c + 0x0f0) = 0x7c;
    *(video + r + c + 0x140) = 0x06;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_6(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x60;
    *(video + r + c + 0x0f0) = 0x7c;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_7(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x7e;
    *(video + r + c + 0x050) = 0x06;
    *(video + r + c + 0x0a0) = 0x06;
    *(video + r + c + 0x0f0) = 0x0c;
    *(video + r + c + 0x140) = 0x0c;
    *(video + r + c + 0x190) = 0x18;
    *(video + r + c + 0x1e0) = 0x18;
    *(video + r + c + 0x230) = 0x00;
}

void show_8(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x3c;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_9(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x3e;
    *(video + r + c + 0x140) = 0x06;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_0(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x66;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

void show_a(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x18;
    *(video + r + c + 0x050) = 0x3c;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x66;
    *(video + r + c + 0x140) = 0x7e;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x66;
    *(video + r + c + 0x230) = 0x00;
}

void show_b(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x7c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x7c;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x7c;
    *(video + r + c + 0x230) = 0x00;
}

void show_c(u32 r, u32 c) {
    r *= 0x280;
    u8* video = (u8*)0xa0000;
    *(video + r + c + 0x000) = 0x3c;
    *(video + r + c + 0x050) = 0x66;
    *(video + r + c + 0x0a0) = 0x66;
    *(video + r + c + 0x0f0) = 0x60;
    *(video + r + c + 0x140) = 0x66;
    *(video + r + c + 0x190) = 0x66;
    *(video + r + c + 0x1e0) = 0x3c;
    *(video + r + c + 0x230) = 0x00;
}

