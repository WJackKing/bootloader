#ifndef INTERRUPTS_H
#define INTERRUPTS_H

#include <utils/port.h>

#define IDT_SIZE 256

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

typedef void (*int_callback)();
void install_int(u32 num, int_callback callback);

void init_interrupts();
void remap_pic();
void registe_ints();
void registe_int(u64 address, u32 num);

void int_hub(u32 num);
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
__attribute__((interrupt)) void int16(int_frame_t* frame);
__attribute__((interrupt)) void int17(int_frame_t* frame);
__attribute__((interrupt)) void int18(int_frame_t* frame);
__attribute__((interrupt)) void int19(int_frame_t* frame);
__attribute__((interrupt)) void int20(int_frame_t* frame);
__attribute__((interrupt)) void int21(int_frame_t* frame);
__attribute__((interrupt)) void int22(int_frame_t* frame);
__attribute__((interrupt)) void int23(int_frame_t* frame);
__attribute__((interrupt)) void int24(int_frame_t* frame);
__attribute__((interrupt)) void int25(int_frame_t* frame);
__attribute__((interrupt)) void int26(int_frame_t* frame);
__attribute__((interrupt)) void int27(int_frame_t* frame);
__attribute__((interrupt)) void int28(int_frame_t* frame);
__attribute__((interrupt)) void int29(int_frame_t* frame);
__attribute__((interrupt)) void int30(int_frame_t* frame);
__attribute__((interrupt)) void int31(int_frame_t* frame);

__attribute__((interrupt)) void int32(int_frame_t* frame);
__attribute__((interrupt)) void int33(int_frame_t* frame);
__attribute__((interrupt)) void int34(int_frame_t* frame);
__attribute__((interrupt)) void int35(int_frame_t* frame);
__attribute__((interrupt)) void int36(int_frame_t* frame);
__attribute__((interrupt)) void int37(int_frame_t* frame);
__attribute__((interrupt)) void int38(int_frame_t* frame);
__attribute__((interrupt)) void int39(int_frame_t* frame);
__attribute__((interrupt)) void int40(int_frame_t* frame);
__attribute__((interrupt)) void int41(int_frame_t* frame);
__attribute__((interrupt)) void int42(int_frame_t* frame);
__attribute__((interrupt)) void int43(int_frame_t* frame);
__attribute__((interrupt)) void int44(int_frame_t* frame);
__attribute__((interrupt)) void int45(int_frame_t* frame);
__attribute__((interrupt)) void int46(int_frame_t* frame);
__attribute__((interrupt)) void int47(int_frame_t* frame);

#endif