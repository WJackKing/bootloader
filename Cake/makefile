target := cake.img
bootloader := bootloader/bootloader.bin
kernel := kernel/kernel.bin

.PHONY: clean $(bootloader) $(kernel)

$(target): $(bootloader) $(kernel)
	@dd if=/dev/zero of=$@ bs=1024 count=16384
	@dd if=$(bootloader) of=$@ bs=512 count=4 conv=notrunc
	@dd if=$(kernel) of=$@ bs=512 seek=4 conv=notrunc

run: $(target)
	@qemu-system-x86_64 -drive format=raw,file=$<

clean:
	@cd bootloader && make clean
	@cd kernel && make clean
	@rm -f $(target)

$(bootloader):
	@cd bootloader && make

$(kernel):
	@cd kernel && make