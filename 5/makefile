target := kernel

src := $(wildcard cpu/*.c io/*.c draw/*.c)
src_asm := $(wildcard cpu/*.asm)
obj := init/loader.o init/kmain.o $(src_asm:.asm=.o) $(src:.c=.o)
bin := boot/boot.bin init/kernel.bin

.PHONY: clean

$(target): $(bin)
	@cat $^ > $@
	
run: $(target)
	@qemu-system-x86_64 -drive format=raw,file=$<
	
clean:
	@rm -f boot/*.bin
	@rm -f init/*.bin
	@rm -f $(obj)
	@rm -f $(target)
	
%.bin: %.asm
	@nasm -fbin -o $@ $<
	
init/kernel.bin: linker.ld $(obj)
	@ld -T $< --oformat binary -o $@ $^

%.o: %.asm
	@nasm -felf64 -o $@ $<

%.o: %.c
	@gcc -c -Iinclude -masm=intel -fno-stack-protector -o $@ $<
