#ifndef KEYBOARD_H
#define KEYBOARD_H

#include <initial/types.h>
#include <cpu/interrupts.h>
#include <driver/graphics.h>
#include <utils/port.h>

void init_keyboard();
void keyboard_callback();

#endif