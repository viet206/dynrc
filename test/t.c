#include "dynrc.h"
#include <stdio.h>

int main() {
	buf_init_static(buf0,32);

	dyn* d = dyn_init(buf0,"Hello World\n",999);
}
