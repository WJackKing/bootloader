#include <driver/keyboard.h>
#include <utils/print.h>

void init_keyboard() {
    asm("cli");
    install_int(1, keyboard_callback);
    asm("sti");
}

void keyboard_callback() {
    u8 code = inb(0x60);
    switch(code) {
    case 0x02:
    case 0x03:
    case 0x04:
    case 0x05:
    case 0x06:
    case 0x07:
    case 0x08:
    case 0x09:
    case 0x0a:
        kprintc(code + 0x2f);
        break;
    case 0x0b:
        back();
        break;
    }
}