#include <driver/graphics.h>

u16* video = (u16*)0xb8000;

void kprint(const u8* str) {
    for(s32 i = 0; str[i] != '\0'; i++) {
        video[i] = str[i] | 0x0f00;
    }
}