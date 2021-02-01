#include <stdio.h>

#define T int
	#include "vect.h"

int main() {
	int nums[] = {-3, -2, -1, 0, 1, 2, 3};
	t_(int, vector) numv = t_(int, initp)(nums);
	numv = t_(int, subs)(&numv, 2, 3);
	printf("%zu // %zu\n", numv.size, numv.cap);
	for (size_t i = 0; i < numv.size; i++) {
		printf("%zu | %d\n", i, numv.data[i]);
	}
	t_(int, free)(&numv);
	return 0;
}
