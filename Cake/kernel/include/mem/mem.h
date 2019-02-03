#ifndef MEM_H
#define MEM_H

#include <initial/types.h>

#define PAGE_SIZE 0x1000
#define MEM_BASE 0x15
#define MEM_EXT 0x17
#define MEM_EXT16 0x34

typedef struct mmap_entry {
    u64 base;
    u64 length;
    u32 type;
    u32 attribute;
}mmap_entry_t;

void init_mem();
void init_mmap();
void print_mmap();

#endif
