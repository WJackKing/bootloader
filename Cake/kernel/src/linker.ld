ENTRY(entry)
SECTIONS {
    . = 0x100000;
    PROVIDE(kernel_start = .);
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .data : {
        *(.data)
    }
    .bss : {
        *(.bss)
    }
    PROVIDE(kernel_end = .);
}
