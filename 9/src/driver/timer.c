#include <driver/timer.h>
#include <driver/screen.h>

u32 timer_counter = 0;

void init_timer() {
    asm("cli");
    install_int(0, timer_callback);
    asm("sti");
}

void timer_callback() {
    timer_counter++;
    show_num(timer_counter % 10, 0, 0);
}

