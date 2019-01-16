target := kernel

obj := init/loader.o
bin := boot/boot.bin init/kernel.bin

.PHONY: clean

$(target): $(bin)
	cat $^ > $@
	
run: $(target)
	qemu-system-i386 $<
	
clean:
	rm boot/*.bin
	rm init/*.o
	rm init/*.bin
	
%.bin: %.asm
	nasm -fbin -o $@ $<
	
init/kernel.bin: linker.ld $(obj)
	ld -m elf_i386 -T $< --oformat binary -o $@ $^

%.o: %.asm
	nasm -felf -o $@ $<
