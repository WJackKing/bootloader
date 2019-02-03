#include <cpu/interrupts.h>
#include <draw/draw_text.h>

idt_entry_t IDT[256];
idt_ptr_t idt_ptr;

void init_interrupts() {
    asm volatile("cli");
    
    remap_pic();
    registe_ints();

    idt_ptr.limit = sizeof(IDT) - 1;
    idt_ptr.base = (u64)IDT;
    asm volatile("lidt %0" :: "m"(idt_ptr));
    
    asm volatile("sti");
}

void remap_pic() {
    outb(0x20, 0x11);
    outb(0xa0, 0x11);
    outb(0x21, 0x20);
    outb(0xa1, 0x28);
    outb(0x21, 0x04);
    outb(0xa1, 0x02);
    outb(0x21, 0x01);
    outb(0xa1, 0x01);
    outb(0x21, 0x00);
    outb(0xa1, 0x00);
    
    outb(0xa1, 0xff);
    outb(0x21, 0xff);
}

void registe_ints() {
    registe_int((u64)int0, 0);
    registe_int((u64)int1, 1);
    registe_int((u64)int2, 2);
    registe_int((u64)int3, 3);
    registe_int((u64)int4, 4);
    registe_int((u64)int5, 5);
    registe_int((u64)int6, 6);
    registe_int((u64)int7, 7);
    registe_int((u64)int8, 8);
    registe_int((u64)int9, 9);
    registe_int((u64)int10, 10);
    registe_int((u64)int11, 11);
    registe_int((u64)int12, 12);
    registe_int((u64)int13, 13);
    registe_int((u64)int14, 14);
    registe_int((u64)int15, 15);
}

void registe_int(u64 address, u32 num) {
    IDT[num].offset_lowerbits = address & 0xffff;
    IDT[num].selector = 0x08; //code segment offset
    IDT[num].ist_index = 0;
    IDT[num].type_attr = 0x8e; //interrupt gate
    IDT[num].offset_middlebits = (address >> 16) & 0xffff;
    IDT[num].offset_higherbits = (address >> 32) & 0xffffffff;
    IDT[num].zero = 0;
}

void int_hub() {
    
}

void int0(int_frame_t* frame) {
    int_hub();
}

void int1(int_frame_t* frame) {
    int_hub();
}

void int2(int_frame_t* frame) {
    int_hub();
}

void int3(int_frame_t* frame) {
    int_hub();
}

void int4(int_frame_t* frame) {
    int_hub();
}

void int5(int_frame_t* frame) {
    int_hub();
}

void int6(int_frame_t* frame) {
    int_hub();
}

void int7(int_frame_t* frame) {
    int_hub();
}

void int8(int_frame_t* frame) {
    int_hub();
}

void int9(int_frame_t* frame) {
    int_hub();
}

void int10(int_frame_t* frame) {
    int_hub();
}

void int11(int_frame_t* frame) {
    int_hub();
}

void int12(int_frame_t* frame) {
    int_hub();
}

void int13(int_frame_t* frame) {
    int_hub();
}

void int14(int_frame_t* frame) {
    int_hub();
}

void int15(int_frame_t* frame) {
    int_hub();
}

