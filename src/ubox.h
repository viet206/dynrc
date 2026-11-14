#ifndef MICRO_BOX_C_H
#define MICRO_BOX_C_H

#define __VERSION "0.0.9"

#define TRUE 1
#define FALSE 0
#define VOID (void*)0

typedef unsigned int uint_t;
typedef unsigned short uhalf_t;
typedef unsigned char uchar_t;
typedef unsigned long long ull_t;

typedef union {
	uhalf_t* h;
	uchar_t* c;
	ull_t* ll;
}r21_t;

int mem_copy(char* restrict dst,char* restrict src,uint_t size);
int mem_clear(char* restrict mem,uint_t size);
int str_to_int(char* restrict num);
uint_t str_size(char* restrict s,uint_t range);
int str_cmp(char* restrict dst,char* restrict src,uint_t n);
int int_to_str(char* buf,uint_t size,int number);

#endif
