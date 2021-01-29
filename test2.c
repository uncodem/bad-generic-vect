#include <stdio.h>

#define T char
	#include "vect.h"

int main() {
	char *first = "Hello, ";
	t_(char, vector) string = t_(char, initp)(first);
	t_(char, join)(&string, t_(char, initp)("World!"), -1);
	printf("%zu | %s\n", string.size, string.data);
	return 0;
}
