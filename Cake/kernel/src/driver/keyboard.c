#include <driver/keyboard.h>
#include <utils/print.h>

u8 qwert_layout[] = {
    0, 0, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    '-', '=', 0, 0, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i',
    'o', 'p', '[', ']', '\n', 0, 'a', 's', 'd', 'f', 'g', 'h',
    'j', 'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 
    'v', 'b', 'n', 'm', ',', '.', '/', 0, '*', 0, ' ', 0
};

u8 qwert_shift_layout[] = {
    0, 0, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
    '_', '+', 0, 0, 'Q', 'W', 'E', 'R', 'T', 'Y', 'U', 'I',
    'O', 'P', '{', '}', '\n', 0, 'A', 'S', 'D', 'F', 'G', 'H',
    'J', 'K', 'L', ':', '\"', '~', 0, '|', 'Z', 'X', 'C',
    'V', 'B', 'N', 'M', '<', '>', '?', 0, '*', 0, ' ', 0
};

void init_keyboard() {
    asm("cli");
    install_int(1, keyboard_callback);
    asm("sti");
}

void keyboard_callback() {
    u8 code = inb(0x60);
    if(code == 0x0e) {
        back();
    }else if(code == 0x36 || code == 0x2a) {
        qwert_layout[0x2a] = 1;
    }else if(code == 0xb6 || code == 0xaa) {
        qwert_layout[0x2a] = 0;
    }else if(code >= 0x01 && code <= 0x3a) {
        if(qwert_layout[0x2a]) {
            code = qwert_shift_layout[code];
        }else{
            code = qwert_layout[code];
        }
        if(code) {
            kprintc(code);
        }
    }
}