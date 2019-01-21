ENTRY(loader)
SECTIONS
{
    . = 0x1000;
    .text : {
        *(.text)
    }
    .rodata : {
        *(.rodata)
    }
    .bss : {
        *(.bss)
    }
    .data : {
        *(.data)
    }
}
