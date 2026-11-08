#include "core.h"

buf* buf_init(char* b,word4 cap) {

#if ENABLE_CHECK == TRUE
	if ( b == NIL ) {
		#if ENABLE_LOG == TRUE
			hal_puts("buf_init : buffer NULL");
		#endif
		return (void*)SIGNAL_NULL;
	}
#endif

	buf* buffer = (buf*) b;
	buffer->cap = cap;
	buffer->cur = 0;

	return buffer;
}

dyn* dyn_init(buf* b,byte* src,word4 tag) {

#if ENABLE_TRACE == TRUE
	if ( b == (void*) SIGNAL_NULL ) {
		#if ENABLE_LOG == TRUE
			hal_puts("dyn_init : buffer null");
		#endif
			return (void*) SIGNAL_NULL;
	}

	if ( src == (void*) SIGNAL_NULL ) {
			#if ENABLE_LOG == TRUE
				hal_puts("dyn_init : src null");
			#endif
				return (void*) SIGNAL_NULL;
	}

#endif

	dyn* d = (dyn*) b->raw;

	switch (tag) {
		case INT:
			d->tag = INT;
			d->i = *((int*)src);
			return d;
		case PTR:
			d->tag = PTR;
			d->v = (void*)src;
			return d;
		case STR_LIT:
			d->tag = STR_LIT;
			d->str_lit = (char*) src;
			return d;
		case UINT:
			d->tag = UINT;
			d->u = *((word4*)src);
			return d;
		default:
			return (void*)SIGNAL_UNDEF_TAG;
	}
}

dyn* str_init(buf* b,char* src,word4 range) {

#if ENABLE_TRACE == TRUE
	if ( b == NIL || src == NIL ) {
		#if ENABLE_LOG == TRUE
			hal_puts("str_init: ptr null");
		#endif
	}
#endif

	dyn* d = (dyn*) b->raw;
	word4 len = compat_str_len(src,range);

	compat_buf_copy((char*)(b + BUFFER_SIZE + DYN_SIZE),src,len);

	return d;
}
