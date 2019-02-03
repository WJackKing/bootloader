#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <init/ctypes.h>
#include <io/port.h>

extern void load_idt(u64 idt_ptr);
extern void int0();
extern void int1();
extern void int2();
extern void int3();
extern void int4();
extern void int5();
extern void int6();
extern void int7();
extern void int8();
extern void int9();
extern void int10();
extern void int11();
extern void int12();
extern void int13();
extern void int14();
extern void int15();

typedef struct idt_entry{
    u16 offset_lowerbits;
    u16 selector;
    u8 ist_index;
    u8 type_attr;
    u16 offset_middlebits;
    u32 offset_higherbits;
    u32 zero;
}__attribute__((packed)) idt_entry_t;

#define IST_NONE 0
#define IST_NMI 1
#define IST_DOUBLE_FAULT 2

void init_interrupts();
extern void int_handler(u32 int_num, u32 err_code);
void remap_pic();
void registe_ints();
void registe_int(u64 address, u32 num, u8 ist_index);

#endif
