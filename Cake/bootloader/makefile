bootloader := bootloader.bin

bin := src/boot/boot.bin src/loader/loader.bin

.PHONY: clean

$(bootloader): $(bin)
	@cat $^ > $@

clean:
	@rm -f $(bin)
	@rm -f $(bootloader)

%.bin: %.asm
	@nasm -fbin -o $@ $<
