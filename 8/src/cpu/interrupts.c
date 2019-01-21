#include <cpu/interrupts.h>

idt_entry_t IDT[IDT_SIZE];
idt_ptr_t idt_ptr;
int_callback int_routines[16];

void install_int(u32 num, int_callback callback) {
    int_routines[num] = callback;
}

void init_interrupts() {
    asm volatile("cli"); //close interrupt
    
    remap_pic(); //remap pic
    registe_ints(); //registe interrupt in IDT array

    idt_ptr.limit = sizeof(IDT) - 1;
    idt_ptr.base = (u64)IDT;
    asm volatile("lidt %0" :: "m"(idt_ptr));
    
    asm volatile("sti"); //start interrupt
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
    
    outb(0xa1, 0x00);
    outb(0x21, 0x00);
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
    registe_int((u64)int16, 16);
    registe_int((u64)int17, 17);
    registe_int((u64)int18, 18);
    registe_int((u64)int19, 19);
    registe_int((u64)int20, 20);
    registe_int((u64)int21, 21);
    registe_int((u64)int22, 22);
    registe_int((u64)int23, 23);
    registe_int((u64)int24, 24);
    registe_int((u64)int25, 25);
    registe_int((u64)int26, 26);
    registe_int((u64)int27, 27);
    registe_int((u64)int28, 28);
    registe_int((u64)int29, 29);
    registe_int((u64)int30, 30);
    registe_int((u64)int31, 31);
    
    registe_int((u64)int32, 32);
    registe_int((u64)int33, 33);
    registe_int((u64)int34, 34);
    registe_int((u64)int35, 35);
    registe_int((u64)int36, 36);
    registe_int((u64)int37, 37);
    registe_int((u64)int38, 38);
    registe_int((u64)int39, 39);
    registe_int((u64)int40, 40);
    registe_int((u64)int41, 41);
    registe_int((u64)int42, 42);
    registe_int((u64)int43, 43);
    registe_int((u64)int44, 44);
    registe_int((u64)int45, 45);
    registe_int((u64)int46, 46);
    registe_int((u64)int47, 47);
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

void int_hub(u32 num) {

    outb(0x20, 0x20);
    if(num >= 40) {
        outb(0xa0, 0x20);
    }
}

void int0(int_frame_t* frame) {
    int_hub(0);
}

void int1(int_frame_t* frame) {
    int_hub(1);
}

void int2(int_frame_t* frame) {
    int_hub(2);
}

void int3(int_frame_t* frame) {
    int_hub(3);
}

void int4(int_frame_t* frame) {
    int_hub(4);
}

void int5(int_frame_t* frame) {
    int_hub(5);
}

void int6(int_frame_t* frame) {
    int_hub(6);
}

void int7(int_frame_t* frame) {
    int_hub(7);
}

void int8(int_frame_t* frame) {
    int_hub(8);
}

void int9(int_frame_t* frame) {
    int_hub(9);
}

void int10(int_frame_t* frame) {
    int_hub(10);
}

void int11(int_frame_t* frame) {
    int_hub(11);
}

void int12(int_frame_t* frame) {
    int_hub(12);
}

void int13(int_frame_t* frame) {
    int_hub(13);
}

void int14(int_frame_t* frame) {
    int_hub(14);
}

void int15(int_frame_t* frame) {
    int_hub(15);
}

void int16(int_frame_t* frame) {
    int_hub(16);
}

void int17(int_frame_t* frame) {
    int_hub(17);
}

void int18(int_frame_t* frame) {
    int_hub(18);
}

void int19(int_frame_t* frame) {
    int_hub(19);
}

void int20(int_frame_t* frame) {
    int_hub(20);
}

void int21(int_frame_t* frame) {
    int_hub(21);
}

void int22(int_frame_t* frame) {
    int_hub(22);
}

void int23(int_frame_t* frame) {
    int_hub(23);
}

void int24(int_frame_t* frame) {
    int_hub(24);
}

void int25(int_frame_t* frame) {
    int_hub(25);
}

void int26(int_frame_t* frame) {
    int_hub(26);
}

void int27(int_frame_t* frame) {
    int_hub(27);
}

void int28(int_frame_t* frame) {
    int_hub(28);
}

void int29(int_frame_t* frame) {
    int_hub(29);
}

void int30(int_frame_t* frame) {
    int_hub(30);
}

void int31(int_frame_t* frame) {
    int_hub(31);
}

void int32(int_frame_t* frame) {
    if(int_routines[0]) {
        int_callback callback = int_routines[0];
        callback();
    }
    int_hub(32);
}

void int33(int_frame_t* frame) {
    if(int_routines[1]) {
        int_callback callback = int_routines[1];
        callback();
    }
    int_hub(33);
}

void int34(int_frame_t* frame) {
    if(int_routines[2]) {
        int_callback callback = int_routines[2];
        callback();
    }
    int_hub(34);
}

void int35(int_frame_t* frame) {
    if(int_routines[3]) {
        int_callback callback = int_routines[3];
        callback();
    }
    int_hub(35);
}

void int36(int_frame_t* frame) {
    if(int_routines[4]) {
        int_callback callback = int_routines[4];
        callback();
    }
    int_hub(36);
}

void int37(int_frame_t* frame) {
    if(int_routines[5]) {
        int_callback callback = int_routines[5];
        callback();
    }
    int_hub(37);
}

void int38(int_frame_t* frame) {
    if(int_routines[6]) {
        int_callback callback = int_routines[6];
        callback();
    }
    int_hub(38);
}

void int39(int_frame_t* frame) {
    if(int_routines[7]) {
        int_callback callback = int_routines[7];
        callback();
    }
    int_hub(39);
}

void int40(int_frame_t* frame) {
    if(int_routines[8]) {
        int_callback callback = int_routines[8];
        callback();
    }
    int_hub(40);
}

void int41(int_frame_t* frame) {
    if(int_routines[9]) {
        int_callback callback = int_routines[9];
        callback();
    }
    int_hub(41);
}

void int42(int_frame_t* frame) {
    if(int_routines[10]) {
        int_callback callback = int_routines[10];
        callback();
    }
    int_hub(42);
}

void int43(int_frame_t* frame) {
    if(int_routines[11]) {
        int_callback callback = int_routines[11];
        callback();
    }
    int_hub(43);
}

void int44(int_frame_t* frame) {
    if(int_routines[12]) {
        int_callback callback = int_routines[12];
        callback();
    }
    int_hub(44);
}

void int45(int_frame_t* frame) {
    if(int_routines[13]) {
        int_callback callback = int_routines[13];
        callback();
    }
    int_hub(45);
}

void int46(int_frame_t* frame) {
    if(int_routines[14]) {
        int_callback callback = int_routines[14];
        callback();
    }
    int_hub(46);
}

void int47(int_frame_t* frame) {
    if(int_routines[15]) {
        int_callback callback = int_routines[15];
        callback();
    }
    int_hub(47);
}

