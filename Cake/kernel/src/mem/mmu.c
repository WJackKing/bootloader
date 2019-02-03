#include <mem/mmu.h>
#include <utils/print.h>

extern u64 pml4;
extern u64 pdpt;
extern u64 pd;

void init_mmu() {
    kprintf("pml4: %p, pdpt: %p, pd: %p\n", pml4, pdpt, pd);
    u64 p = pml4 & ~0xfff;
    kprintf("%p\n", p);
}