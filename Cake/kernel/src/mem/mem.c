#include <mem/mem.h>
#include <utils/port.h>
#include <utils/print.h>

extern u8 kernel_start[];
extern u8 kernel_end[];
u64 usable_start = 0;
u64 usable_length = 0;
u64 usable_end = 0;
u64 mem_total = 0;

void init_mem() {
    init_mmap();
    print_mmap();
    kprintf("usable start: %p, usable end: %p\n", usable_start, usable_end);
}

void init_mmap() {
    mmap_entry_t* mmap = (mmap_entry_t*)0x9000;
    while(mmap->type) {
        if(mmap->type == 1) {
            if(mmap->length > usable_length) {
                usable_start = mmap->base;
                usable_end = mmap->base + mmap->length;
            }
        }
        mmap++;
    }
}

void print_mmap() {
    kprintf("kernel start: %p\n", kernel_start);
    kprintf("kernel end: %p\n", kernel_end);
    kprints("Memory map:\n");
    mmap_entry_t* mmap = (mmap_entry_t*)0x9000;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
    mmap++;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
    mmap++;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
    mmap++;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
    mmap++;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
    mmap++;
    kprintf("base: %p, length: %p, type: %p\n", mmap->base, mmap->length, mmap->type);
}
