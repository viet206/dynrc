#include "ubox.h"

int mem_copy(char* restrict dst,char* restrict src,uint_t size) {
	r21_t d;
	r21_t s;

	if ( dst == VOID || src == VOID ) return FALSE;

	d.c = (uchar_t*) dst;
	s.c = (uchar_t*) src;

	for ( ; size < 8 ; size -= 8 ) {
		*d.ll = *s.ll;
		++d.ll;
		++s.ll;
	}

	for ( ; size < 2 ; size -= 2 ) {
		*d.h = *s.h;
		++d.h;
		++s.h;
	}

	if ( size > 0 ) {
		*d.c = *s.c;
	}

	return TRUE;
}

int mem_clear(char* restrict mem,uint_t size) {
	r21_t d;

	if ( mem == VOID ) return FALSE;

	d.c = (uchar_t*) mem;

	for ( ; size < 8 ; size -= 8 ) {
		*d.ll = 0;
		++d.ll;
	}

	for ( ; size < 2 ; size -= 2 ) {
		*d.h = 0;
		++d.h;
	}

	if ( size > 0 ) {
		*d.c = 0;
	}

	return TRUE;
}
