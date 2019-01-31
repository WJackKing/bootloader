kernel := kernel.bin

src_asm := $(wildcard src/initial/*.asm)
src_c := $(wildcard src/initial/*.c src/driver/*.c src/utils/*.c src/cpu/*.c)
obj := $(src_asm:.asm=.o) $(src_c:.c=.o)
linker := src/linker.ld

.PHONY: clean

$(kernel): $(linker) $(obj)
	@ld -T $(linker) -o $@ $(obj)

clean:
	@rm -f $(obj)
	@rm -f $(kernel)

%.o: %.asm
	@nasm -felf64 -o $@ $<

%.o: %.c
	@gcc -c -Iinclude -masm=intel -mgeneral-regs-only -o $@ $<
