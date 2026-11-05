#ifndef CORE
#define CORE

/* Quy ước đặt tên
 * + [action]_[name] cho hàm
 * + [name]_[noun] cho biến
*/

#include "hal/hal.h"
#include "compat/compat.h"
#include "trace.h"

#define ENABLE_TRACE TRUE
#define DYN_SIZE (int)sizeof(dyn)
#define BUFFER_SIZE (int)sizeof(buf)

typedef unsigned char byte;
typedef unsigned long long word8;
typedef unsigned short word2;
typedef unsigned int word4;

typedef enum {
		PTR,
		INT,
		UINT,
		STR_LIT
}tag_value;

typedef struct {
	tag_value tag;
	union {
		word4 u;
		int i;
		void* v;
		char* str_lit;
		struct {
			char* s;
			word4 len;
		};
	};
}dyn;

typedef struct {
	word4 cur;
	word4 cap;
	byte raw[];
}buf;

buf* buf_init(char* b,word4 cap);

dyn* dyn_init(buf* b,byte* src,word4 tag);

dyn* dyn_str(buf* b,char* src,word4 range);

dyn* init_list(buf* b,word4 elm);

#endif
