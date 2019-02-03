#include <driver/keyboard.h>

void init_keyboard() {
    asm("cli");
    install_int(1, keyboard_callback);
    asm("sti");
}

void keyboard_callback() {
    u8 code = inb(0x60);
    switch(code) {
    case 0x02:
        show_1(1, 0);
        break;
    case 0x03:
        show_2(1, 0);
        break;
    case 0x04:
        show_3(1, 0);
        break;
    case 0x05:
        show_4(1, 0);
        break;
    case 0x06:
        show_5(1, 0);
        break;
    case 0x07:
        show_6(1, 0);
        break;
    case 0x08:
        show_7(1, 0);
        break;
    case 0x09:
        show_8(1, 0);
        break;
    case 0x0a:
        show_9(1, 0);
        break;
    case 0x0b:
        show_0(1, 0);
        break;
    }
}

