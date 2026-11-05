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

typedef unsigned char byte;
typedef unsigned long long word8;
typedef unsigned short word2;
typedef unsigned int word4;

typedef struct {
	enum {
		PTR,
		INT,
		UINT,
		STR_LIT
	};
	union {
		word4 u;
		int i;
		void* v;
		char* s;
	};
}dyn;

typedef struct {
	word4 cur;
	word4 cap;
	byte raw[];
}buf;

buf* init_buf(byte* b,word4 cap);
dyn* init_dyn(buf* b,byte* src,word4 tag);
dyn** init_list(buf* b,word4 elm);

#endif
