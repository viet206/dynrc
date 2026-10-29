#include <stdio.h>
#include "hal.h"

void hal_puts(char* s) {
	printf("%s",s);
}

int hal_getln(char* buf,int size) {
	return *(int*) fgets(buf,size,stdin);
}
