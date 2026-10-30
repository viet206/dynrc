#include "core.h"

#define add_type(name,member,cast) \
	case name: \
		d->tag = tag; \
		d->member = cast src; \
		break;

#define cmp_type(name,member) \
	case name: \
		return ( d->member == d1->member )

dyn* dyn_init(buf* b,char* src,dtag tag) {
	if ( b == ptr(0) && src == ptr(0) ) return ptr(0);

	// make dyn
	dyn* d = (dyn*) b->data;

	switch (tag) {
		add_type(INT,i,*(int*));
		add_type(PTR,p,(void*));
		add_type(STR_LIT,s,(char*));
		default:
			return ptr(UNDEFINED_TAG);
	}
	return d;
}

sig dyn_cmp(dyn* d,dyn* d1) {
	if ( d == ptr(0) || d == ptr(0) ) return PTR_NIL;

	if ( d->tag != d1->tag ) return TAG_NEQ;

	switch (d->tag) {
		cmp_type(INT,i);
		cmp_type(PTR,p);
		default:
			return 1;
	}
}
