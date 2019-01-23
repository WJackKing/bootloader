#include <init/kmain.h>

extern void kmain(u32 frame_buffer) {
    init_cpu();
    init_driver();
    show_A(0, 0);
    while(1);
}
