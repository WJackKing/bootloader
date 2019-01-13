target := boot/boot

$(target): boot/boot.asm
	nasm -o $@ $<
	
run: $(target)
	qemu-system-i386 $<
