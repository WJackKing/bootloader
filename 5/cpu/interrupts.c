#include <cpu/interrupts.h>
#include <draw/draw_text.h>

idt_entry_t IDT[256];
u64 idt_ptr[2];

void init_interrupts() {
    remap_pic();
    registe_ints();

    idt_ptr[0] = sizeof(IDT) - 1; //limit
    idt_ptr[1] = (u64)IDT >> 16; //address
    load_idt((u64)idt_ptr);
}

void int_handler(u32 int_num, u32 err_code) {
    outb(0x20, 0x20);
    while(1); //not success in there, need to check how to save register states
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
    registe_int((u64)int0, 0, IST_NONE);
    registe_int((u64)int1, 1, IST_NONE);
    registe_int((u64)int2, 2, IST_NMI);
    registe_int((u64)int3, 3, IST_NONE);
    registe_int((u64)int4, 4, IST_NONE);
    registe_int((u64)int5, 5, IST_NONE);
    registe_int((u64)int6, 6, IST_NONE);
    registe_int((u64)int7, 7, IST_NONE);
    registe_int((u64)int8, 8, IST_DOUBLE_FAULT);
    registe_int((u64)int9, 9, IST_NONE);
    registe_int((u64)int10, 10, IST_NONE);
    registe_int((u64)int11, 11, IST_NONE);
    registe_int((u64)int12, 12, IST_NONE);
    registe_int((u64)int13, 13, IST_NONE);
    registe_int((u64)int14, 14, IST_NONE);
    registe_int((u64)int15, 15, IST_NONE);
}

void registe_int(u64 address, u32 num, u8 ist_index) {
    IDT[num].offset_lowerbits = address & 0xffff;
    IDT[num].selector = 0x08; //code segment offset
    IDT[num].ist_index = ist_index;
    IDT[num].type_attr = 0x8e; //interrupt gate
    IDT[num].offset_middlebits = (address >> 16) & 0xffff;
    IDT[num].offset_higherbits = (address >> 32) & 0xffffffff;
    IDT[num].zero = 0;
}


