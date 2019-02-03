#include <driver/graphics.h>

Buffer buffer = {0, 0, {CHAR}};
const u8 c_table[16] = {'0', '1', '2', '3', '4', '5', '6', '7',
					    '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
u8 n_buffer[64] = {0};
u8 pos = 0;

void write_char(u8 c) {
	write_char_color(c, COLOR);
}

void write_char_color(u8 c, u8 color) {
	switch(c) {
		case '\n':
			new_line();
			break;
		default:
			buffer.buf[buffer.x][buffer.y] = c << 8 | color;
			buffer.y++;
	}
	if(buffer.y >= 80) {
		new_line();
	}
}

void write_str(u8 *str) {
	write_str_color(str, COLOR);
}

void write_str_color(u8 *str, u8 color) {
	while(*str) {
		write_char_color(*str++, color);
	}
}

void write_int(s64 value, u8 base) {
	write_int_color(value, base, COLOR);
}

void write_int_color(s64 value, u8 base, u8 color) {
	if(value < 0) {
		write_char_color('-', color);
		write_uint_color((u64)-value, base, color);
	}else{
		write_uint_color((u64)value, base, color);
	}
}

void write_uint(u64 value, u8 base) {
	write_uint_color(value, base, COLOR);
}

void write_uint_color(u64 value, u8 base, u8 color) {
	if(base < 2 || base > 16) {
		return;
	}

	while(value) {
		n_buffer[pos] = (u8) value % base;
		pos++;
		value /= base;
	}

	if(pos == 0) {
		write_char_color('0', color);
		return;
	}
	for(s32 i = pos - 1; i >= 0; i--) {
		write_char_color(c_table[n_buffer[i]], color);
	}

	pos = 0;
}

void new_line() {
	buffer.x++;
	if(buffer.x >= BUF_HEIGHT) {
		for(u32 i = 1; i < BUF_HEIGHT; i++) {
			for(u32 j = 0; j < BUF_WIDTH; j++) {
				buffer.buf[i - 1][j] = buffer.buf[i][j];
				buffer.buf[i][j] = CHAR;
			}
		}
		buffer.y = 0;
		buffer.x--;
	}else{
		buffer.y = 0;
	}
}

void clear_buffer() {
	buffer.x = 0;
	buffer.y = 0;
	for(u32 i = 0; i < BUF_HEIGHT; i++) {
		for(u32 j = 0; j < BUF_WIDTH; j++) {
			buffer.buf[i][j] = CHAR;
		}
	}
}

void buf_back() {
	if(buffer.y >= 1) {
		buffer.y--;
		buffer.buf[buffer.x][buffer.y] = CHAR;
	}else if(buffer.x >= 1) {
		buffer.y = BUF_WIDTH - 1;
		buffer.x--;
		buffer.buf[buffer.x][buffer.y] = CHAR;
	}
}

void flush() {
	volatile u8 *video = (volatile u8 *)0xb8000;
	for(u32 i = 0; i < BUF_HEIGHT; i++) {
		for(u32 j = 0; j < BUF_WIDTH; j++) {
			*video++ = buffer.buf[i][j] >> 8;
			*video++ = buffer.buf[i][j];
		}
	}
	update_cursor(buffer.x, buffer.y);
}

void update_cursor(u32 x, u32 y) {
	u32 p = x * BUF_WIDTH + y;
	outb(0x3d4, 0x0e);
	outb(0x3d5, p >> 8);
	outb(0x3d4, 0x0f);
	outb(0x3d5, p & 0xff);
}

void get_buf_str(u32 start, u32 end, u8 *out) {
	for(u32 i = start; i < end; i++) {
		out[i - start] = buffer.buf[i/BUF_WIDTH][i%BUF_WIDTH] >> 8;
	}
}

void enable_cursor() {
	outb(0x3d4, 0x0a);
	outb(0x3d5, (inb(0x3d5) & 0xc0) | 13);
	outb(0x3d4, 0x0b);
	outb(0x3d5, (inb(0x3d5) & 0xe0) | 15);
}

void init_graphics() {
    clear_buffer();
	enable_cursor();
	flush();
}