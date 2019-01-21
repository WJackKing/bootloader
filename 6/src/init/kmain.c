#include <init/kmain.h>

extern void kmain() {
    init_cpu();
    show_a(0, 0);
    show_1(0, 1);
    show_2(0, 2);
    show_3(0, 3);
    show_4(0, 4);
    show_5(0, 5);
    show_b(59, 79);
    for(s32 i = 1; i < 59; i++) {
        for(s32 j = 1; j < 79; j++) {
            show_a(i, j);
        }
    }
    while(1);
}
