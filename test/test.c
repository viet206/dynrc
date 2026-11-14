#include "ubox.h"
#include <stdio.h>

#define PRINT_MSG(str,var) printf(str,var)

int main() {
	char buf[64];
	PRINT_MSG("len of \"Hello World\": %d\n",str_size("Hello World",15));
	PRINT_MSG("string cmp: %d\n",str_cmp("Hello","Hello World",4));
	PRINT_MSG("number \"4567\" : %d\n",str_to_int("4567"));
	int_to_str(buf,64,-234);
	PRINT_MSG("string -234: %s",buf);
}
