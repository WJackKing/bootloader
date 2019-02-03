#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <init/ctypes.h>
#include <io/port.h>

typedef struct idt_entry {
    u16 offset_lowerbits;
    u16 selector;
    u8 ist_index;
    u8 type_attr;
    u16 offset_middlebits;
    u32 offset_higherbits;
    u32 zero;
}__attribute__((packed)) idt_entry_t;

typedef struct int_frame {
    u64 rip, cs, rflags, rsp, ss;
}int_frame_t;

typedef struct idt_ptr {
    u16 limit;
    u64 base;
}__attribute__((packed)) idt_ptr_t;

void int_hub();
__attribute__((interrupt)) void int0(int_frame_t* frame);
__attribute__((interrupt)) void int1(int_frame_t* frame);
__attribute__((interrupt)) void int2(int_frame_t* frame);
__attribute__((interrupt)) void int3(int_frame_t* frame);
__attribute__((interrupt)) void int4(int_frame_t* frame);
__attribute__((interrupt)) void int5(int_frame_t* frame);
__attribute__((interrupt)) void int6(int_frame_t* frame);
__attribute__((interrupt)) void int7(int_frame_t* frame);
__attribute__((interrupt)) void int8(int_frame_t* frame);
__attribute__((interrupt)) void int9(int_frame_t* frame);
__attribute__((interrupt)) void int10(int_frame_t* frame);
__attribute__((interrupt)) void int11(int_frame_t* frame);
__attribute__((interrupt)) void int12(int_frame_t* frame);
__attribute__((interrupt)) void int13(int_frame_t* frame);
__attribute__((interrupt)) void int14(int_frame_t* frame);
__attribute__((interrupt)) void int15(int_frame_t* frame);

void init_interrupts();
void remap_pic();
void registe_ints();
void registe_int(u64 address, u32 num);

#endif
