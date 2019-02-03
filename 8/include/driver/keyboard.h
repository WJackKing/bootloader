#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <init/ctypes.h>
#include <cpu/interrupts.h>
#include <driver/screen.h>
#include <io/port.h>

void init_keyboard();
void keyboard_callback();

#endif
