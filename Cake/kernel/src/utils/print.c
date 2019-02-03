#include <utils/print.h>

void kprintc(u8 c) {
	write_char(c);
	flush();
}

void kprinti(s64 n) {
	write_int(n, 10);
	flush();
}

void kprintu(u64 n) {
	write_uint(n, 10);
	flush();
}

void kprints(u8 *str) {
	write_str(str);
	flush();
}

void kprintsc(u8 *str, u8 color) {
	write_str_color(str, color);
	flush();
}

void kprintf(u8 *str, ...) {
	u64 *p_arg = (u64*)&str;
	p_arg += 4;

	while(*str != 0) {
		u8 tmp = *str++;
		if(tmp == '%') {
			switch(*str++) {
				case 'd':
					write_int(*((s64*)p_arg), 10);
					p_arg++;
					break;
				case 'x':
					write_int(*((s64*)p_arg), 16);
					p_arg++;
					break;
				case 'u':
					write_uint(*((u64*)p_arg), 10);
					p_arg++;
					break;
				case 'p':
					write_uint(*((u64*)p_arg), 16);
					p_arg++;
					break;
				case 'c':
					write_char(*((u8*)p_arg));
					p_arg++;
					break;
				case 's':
					write_str(*((u8**)p_arg));
					p_arg++;
					break;
			}
		}else{
			write_char(tmp);
		}
	}
	flush();
}

void back() {
	buf_back();
	flush();
}

void clear() {
	clear_buffer();
	flush();
}