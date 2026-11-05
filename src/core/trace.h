#ifndef TRACE
#define TRACE

#include "core.h"

char* output_signal(sig s);

void trace_int(int i);
void trace_str(char* s);
void trace_size(uint_t u);
void trace_buffer(buf* b);

#endif
