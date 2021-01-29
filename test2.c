#include <stdio.h>

#define T char
	#include "vect.h"

int main() {
	char *first = "Hello, ";
	t_(char, vector) string = t_(char, initnp)(first, sizeof(first)-1);
	t_(char, join)(&string, t_(char, initp)("World!"), 0);
	printf("%zu | %s\n", string.size, string.data);
	return 0;
}
