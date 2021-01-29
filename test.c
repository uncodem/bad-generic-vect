#include <stdio.h>

#define T int
	#include "vect.h"

int main() {
	int arr[4] = {5, 6, 7, 8};
	t_(int, vector) nums = t_(int, init)();

	t_(int, append)(&nums, 1);
	t_(int, append)(&nums, 2);
	t_(int, append)(&nums, 3);
	t_(int, append)(&nums, 4);
	t_(int, join)(&nums, t_(int, initnp)(arr, 4), 0);
	printf("%zu // %zu\n", nums.size, nums.cap);

	for (size_t i = 0; i < nums.size; i++) {
		printf("%zu : %d\n", i, nums.data[i]);
	}
	
	t_(int, free)(&nums);
	return 0;
}
