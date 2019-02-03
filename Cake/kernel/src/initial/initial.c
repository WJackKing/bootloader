#include <initial/initial.h>
#include <driver/graphics.h>
#include <mem/mmu.h>
#include <mem/mem.h>
#include <cpu/interrupts.h>
#include <driver/timer.h>
#include <driver/keyboard.h>

#include <utils/print.h>

extern void initial() {
    init_graphics();
    init_mmu();
    init_mem();
    init_interrupts();
    init_timer();
    init_keyboard();
    kprintsc("$", 0x0a);
    while(1) {}
}
