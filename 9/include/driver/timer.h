#ifndef TIMER_H
#define TIMER_H

#include <init/ctypes.h>
#include <cpu/interrupts.h>

void init_timer();
void timer_callback();

#endif
