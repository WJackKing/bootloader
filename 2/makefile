target := boot/boot

$(target): boot/boot.o boot/loader.o
	cat boot/boot.o boot/loader.o > $@
	
run: $(target)
	qemu-system-i386 $<
	
%.o: %.asm
	nasm -o $@ $<
