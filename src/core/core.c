#include "core.h"

buf* buf_init(char* b,word4 cap) {

	buf* buffer = (buf*) b;
	buffer->cap = cap;
	buffer->cur = 0;

	return buffer;
}

dyn* dyn_init(buf* b,byte* src,word4 tag) {

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

	dyn* d = (dyn*) b->raw;
	word4 len = compat_str_len(src,range);

	compat_buf_copy((char*)(b + BUFFER_SIZE + DYN_SIZE),src,len);

	return d;
}
