#ifndef COMPAT
#define COMPAT

#define NIL (void*)0
#define TRUE 1
#define FALSE 0

typedef unsigned int uint_t;

int compat_str_cmp(char* d, char* d1, uint_t n);
uint_t compat_str_len(char* s, uint_t range);
int compat_buf_copy(char* dst, char* src, uint_t size);
int compat_buf_clear(char* buf, uint_t size);

#endif
