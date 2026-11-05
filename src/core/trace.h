#ifndef TRACE
#define TRACE

#include "core.h"

typedef enum {
	SIGNAL_SUCCESS,
	SIGNAL_FAILURE,
	SIGNAL_UNDEF_TAG,
	SIGNAL_NULL_PTR,
	SIGNAL_TAG_NEQ
}rt_signal;

char* str_signal(rt_signal sig);

void trace(rt_signal sig,char* message);

#endif
