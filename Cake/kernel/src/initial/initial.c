#include <initial/initial.h>
#include <driver/graphics.h>
#include <cpu/interrupts.h>
#include <driver/timer.h>
#include <driver/keyboard.h>

extern void initial() {
    init_interrupts();
    init_timer();
    init_keyboard();
    kprint("hello");
    while(1) {}
}