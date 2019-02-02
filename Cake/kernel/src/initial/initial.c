#include <initial/initial.h>
#include <driver/graphics.h>
#include <cpu/interrupts.h>
#include <driver/timer.h>
#include <driver/keyboard.h>

#include <utils/print.h>

extern void initial() {
    init_graphics();
    init_interrupts();
    init_timer();
    init_keyboard();
    while(1) {}
}
