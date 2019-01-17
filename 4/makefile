target := kernel

obj := init/loader.o init/kmain.o
bin := boot/boot.bin init/kernel.bin

.PHONY: clean

$(target): $(bin)
	@cat $^ > $@
	
run: $(target)
	@qemu-system-x86_64 -drive format=raw,file=$<
	
clean:
	@rm -f boot/*.bin
	@rm -f init/*.o
	@rm -f init/*.bin
	@rm -f $(target)
	
%.bin: %.asm
	@nasm -fbin -o $@ $<
	
init/kernel.bin: linker.ld $(obj)
	@ld -T $< --oformat binary -o $@ $^

%.o: %.asm
	@nasm -felf64 -o $@ $<

%.o: %.c
	@gcc -c -Iinclude -o $@ $<
