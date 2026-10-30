#ifndef CORE
#define CORE

#include "compat/compat.h"
#include "hal/hal.h"

#define AUTO_CHECKER TRUE

typedef unsigned int uint_t;

typedef union {
	char* s;
	int* i;
}ptr;

typedef enum {
	INT,
	STR_LIT,
	PTR
}dtag; // data tag

typedef struct {
	dtag tag;
	union {
		int i;
		char* s;
		void* p;
	};
}dyn;

typedef struct {
	uint_t cur;
	uint_t cap;
	char data[];
}buf;

typedef struct {
	uint_t elm;
	uint_t cur;
	dyn* d;
}arg;

typedef enum {
	ENO_SIZE,
	UNDEFINED_TAG,
	BUFFER_NIL,
	TAG_NEQ,
	PTR_NIL
}sig;

#define ptr(value) (void*)value
#define obj_free(obj) obj = ptr(0)

#define buf_init_static(name,size) \
	char buf_##name[size] = {0}; \
	buf* name = (buf*) buf_##name; \
	name->cap = size; \
	name->cur = 0;

#define dyn_tagof(dyn) dyn->tag

#define is_num(num) ( num >= '0' && num <= '9' )

// New API for Next Version

sig buf_clear(buf* b);
sig buf_copy(buf* b,buf* b1);

dyn* dyn_init(buf* b,char* src,dtag tag);
sig dyn_cmp(dyn* d,dyn* d1);

dyn* str_init(buf* b,char* src,uint_t range);
dyn* str_cmp(dyn* d,dyn* d1);
int str_to_int(dyn* d);

#endif
