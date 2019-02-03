#ifndef SCREEN_H
#define SCREEN_H

#include <init/ctypes.h>

typedef void (*show_fun_p)(u32 r, u32 c);

void init_screen();

void show_num(u32 n, u32 r, u32 c);
void show_space(u32 r, u32 c);
void show_1(u32 r, u32 c);
void show_2(u32 r, u32 c);
void show_3(u32 r, u32 c);
void show_4(u32 r, u32 c);
void show_5(u32 r, u32 c);
void show_6(u32 r, u32 c);
void show_7(u32 r, u32 c);
void show_8(u32 r, u32 c);
void show_9(u32 r, u32 c);
void show_0(u32 r, u32 c);
void show_A(u32 r, u32 c);
void show_B(u32 r, u32 c);
void show_C(u32 r, u32 c);

#endif
