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
	dyn_tag tag;
	union {
		int i;
		char* s;
		void* p;
	};
}dyn;

typedef struct {
	uint_t size;
	uint_t cap;
	char data[];
}buf;

typedef enum {
	ENO_SIZE,
	UNDEFINED_TAG,
	BUFFER_NIL
}sig;

buf* buf_init(char* raw,uint_t size);
sig buf_clear(buf* b);
sig buf_copy(buf* b,buf* b1);
dyn* dyn_init(buf* b,char* src,dtag tag);
dtag dyn_tagof(dyn* d);

#endif
