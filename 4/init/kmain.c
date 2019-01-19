#include <init/kmain.h>

extern void kmain() {
    show_a(0, 0);
    show_b(59, 79);
    for(s32 i = 1; i < 59; i++) {
        for(s32 j = 1; j < 79; j++) {
            show_2(i, j);
        }
    }
    while(1);
}
