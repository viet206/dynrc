#include "trace.h"

char* str_signal(rt_signal s) {
	switch (s) {
		case SIGNAL_SUCCESS:
			return (void*)0xFFFF;
		case SIGNAL_UNDEF_TAG:
			return "undefined tag";
		case SIGNAL_NULL_PTR:
			return "pointer value 0x0";
		default:
			return "unknown signal";
	}
}

void trace(rt_signal sig,char* message) {
	char buf[256] = {0};
	word4 msg_len = compat_str_len(message,128);
	word4 sig_len;
	
	if ( sig >= SIGNAL_SUCCESS && sig <= SIGNAL_FAILURE ) {
		char* ss = str_signal(sig);
		sig_len = compat_str_len(message,32);

		compat_buf_copy(buf,message,msg_len);
		compat_buf_copy(buf + msg_len,ss,sig_len);
		
		hal_puts(buf);
	}
}
