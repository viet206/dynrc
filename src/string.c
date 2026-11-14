#include "ubox.h"

int str_to_int(char* restrict num) {
	int number = 0;

	if ( num == VOID ) return FALSE;

	for ( int i = 0 ; num[i] != '\0' ; i++ ) {
		if ( num[i] >= '0' && num[i] <= '9' ) number = number * 10 + ( num[i] - '0' );
	}
	
	return number;
}

uint_t str_size(char* restrict s,uint_t range) {
	uint_t length = 0;

	if ( s == VOID ) return FALSE;

	for ( ; length <= range ; length++ ) {
		if ( s[length] == '\0' ) break;
	}

	return length;
}

int str_cmp(char* restrict dst,char* restrict src,uint_t n) {

	if ( dst == VOID || src == VOID ) return FALSE;

	for ( uint_t i = 0 ; i <= n ; i++ ) {
		if ( *dst == *src ) return TRUE;
		++dst;
		++src;
	}
	return FALSE;
}

int int_to_str(char* buf, uint_t size, int number) {
    uint_t i = 0;
    uint_t cur;
    int n = number;
    char tmp;

    if (buf == VOID || size == 0)
        return FALSE;

    // Xử lý số âm
    if (n < 0)
    {
        if (size < 2)
            return FALSE;

        buf[i++] = '-';
    }

    // Xử lý số INT_MIN an toàn
    unsigned int value = (n < 0) ? (unsigned int)(-(n + 1)) + 1
                                  : (unsigned int)n;

    // Trường hợp number = 0
    if (value == 0)
    {
        if (i + 1 >= size)
            return FALSE;

        buf[i++] = '0';
    }

    // Chuyển từng chữ số
    while (value > 0)
    {
        if (i + 1 >= size)
            return FALSE;

        buf[i++] = (value % 10) + '0';
        value /= 10;
    }

    // Đảo phần chữ số, giữ nguyên dấu âm
    cur = (n < 0) ? 1 : 0;

    uint_t left = cur;
    uint_t right = i - 1;

    while (left < right)
    {
        tmp = buf[left];
        buf[left] = buf[right];
        buf[right] = tmp;

        left++;
        right--;
    }

    buf[i] = '\0';

    return TRUE;
}
