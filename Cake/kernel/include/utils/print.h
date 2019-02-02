#ifndef IO_H
#define IO_H

#include <initial/types.h>
#include <driver/graphics.h>

void kprintc(u8 c);
void kprinti(s64 n);
void kprintu(u64 n);
void kprints(u8 *);
void kprintsc(u8 *str, u8 color);
void kprintf(u8 *str, ...);
void back();
void clear();

#endif