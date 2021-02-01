#include <stdio.h>

#define T int
	#include "vect.h"

int main() {
	int arr[4] = {6, 7, 8, 9};
	t_(int, vector) nums = t_(int, init)();

	t_(int, append)(&nums, 1);
	t_(int, append)(&nums, 2);
	t_(int, append)(&nums, 3);
	t_(int, append)(&nums, 4);
	t_(int, join)(&nums, t_(int, initnp)(arr, 4), 0);
	t_(int, vector) nums2 = t_(int, subs)(&nums, 0, 3);

	printf("%zu // %zu\n", nums2.size, nums2.cap);

	for (size_t i = 0; i < nums2.size; i++) {
		printf("%zu : %d\n", i, nums2.data[i]);
	}
	
	t_(int, free)(&nums);
	return 0;
}
