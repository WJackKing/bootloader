#include <driver/keyboard.h>

void show() {
    show_1(1, 0);
}

void init_keyboard() {
    asm("cli");
    install_int(1, show);
    asm("sti");
}
