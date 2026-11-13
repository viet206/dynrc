#ifndef MICRO_BOX_C_H
#define MICRO_BOX_C_H

#define __VERSION "0.0.9"

typedef unsigned int uint_t;
typedef unsigned short uhalf_t;
typedef unsigned char uchar_t;
typedef unsigned long long ull_t;

int copymem(char* restrict dst,char* restrict src,uint_t size);
int clearmem(char* restrict mem,uint_t size);
int str2int(char* restrict num);
uint_t strsize(char* restrict s,uint_t range);
int str_cmp(char* restrict dst,char* restrict src,uint_t n);

#endif
