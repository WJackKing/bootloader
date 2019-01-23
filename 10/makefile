target := kernel

src := $(wildcard src/cpu/*.c src/util/*.c src/driver/*.c src/init/*.c)
obj := src/init/loader.o $(src:.c=.o)
bin := src/boot/boot.bin src/init/kernel.bin

.PHONY: clean

$(target): $(bin)
	@cat $^ > $@
	
run: $(target)
	@qemu-system-x86_64 -drive format=raw,file=$<
	
clean:
	@rm -f $(obj)
	@rm -f $(bin)
	@rm -f $(target)
	
src/boot/boot.bin: src/boot/boot.asm
	@nasm -fbin -o $@ $<
	
src/init/kernel.bin: linker.ld $(obj)
	@ld -T $< --oformat binary -o $@ $^

%.o: %.asm
	@nasm -felf64 -o $@ $<

%.o: %.c
	@gcc -c -Iinclude -masm=intel -fno-stack-protector -mgeneral-regs-only -o $@ $<
