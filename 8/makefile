target := kernel

src := $(wildcard src/cpu/*.c src/io/*.c src/driver/*.c src/draw/*.c)
src_asm := $(wildcard src/cpu/*.asm)
obj := src/init/loader.o src/init/kmain.o $(src_asm:.asm=.o) $(src:.c=.o)
bin := src/boot/boot.bin src/init/kernel.bin

.PHONY: clean

$(target): $(bin)
	@cat $^ > $@
	
run: $(target)
	@qemu-system-x86_64 -drive format=raw,file=$<
	
clean:
	@rm -f $(bin)
	@rm -f $(obj)
	@rm -f $(target)
	
%.bin: %.asm
	@nasm -fbin -o $@ $<
	
src/init/kernel.bin: linker.ld $(obj)
	@ld -T $< --oformat binary -o $@ $^

%.o: %.asm
	@nasm -felf64 -o $@ $<

%.o: %.c
	@gcc -c -Iinclude -masm=intel -fno-stack-protector -mgeneral-regs-only -o $@ $<
