#include "trace.h"

char* output_signal(sig s) {
	switch (s) {
		case ENO_SIZE:
			return "enough size";
		case UNDEFINED_TAG:
			return "undefined tag";
		case PTR_NIL:
			return "pointer value 0x0";
		default:
			return "unknown signal";
	}
}
