#ifndef CORE
#define CORE

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

typedef enum {
	ENO_SIZE,
	UNDEFINED_TAG,
	BUFFER_NIL,
	TAG_NEQ,
	PTR_NIL
}sig;

#define ptr(value) (void*)value

#define buf_free(buf) buf == ptr(0)
#define dyn_free(dyn) dyn == ptr(0)

#define buf_init_static(name,size) \
	char buf_##name[size] = {0}; \
	buf* name = (buf*) buf_##name; \
	name->cap = size; \
	name->cur = 0;

#define dyn_tagof(dyn) dyn->tag

dyn* dyn_init(buf* b,char* src,dtag tag);
sig dyn_cmp(dyn* d,dyn* d1);

#endif
