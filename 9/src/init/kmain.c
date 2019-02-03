#include <init/kmain.h>

extern void kmain() {
    init_cpu();
    init_driver();
    show_a(0, 0);
    show_b(59, 79);
    while(1);
}
