/* This header is meant to be included multiple times to generate */
/* multiple vectors for multiple types */
/* NOTE: when using this library, please add a flag */
/* so that the vector can be freed clearly if it is an array of pointers */
#include <stdio.h>
#include "templ.h"
#include <stdlib.h>
#include <stdint.h>

#ifndef TEMPL_H_
#define TEMPL_H_

#define CAT(a, b) a##_##b
#define TEMPL(x, y) CAT(x,y)
#define t_(type, name) TEMPL(type, name)

#endif

#ifndef VECT_CONSTS
#define VECT_CONSTS
#define VECT_FACT 2
#define VECT_THRESH 8
#endif

#ifdef T
#define VT(name) t_(T, name)

typedef struct {
	T *data;
	size_t size;
	size_t cap;
} VT(vector);

VT(vector) VT(init)() {
	VT(vector) ret;
	ret.cap = VECT_THRESH;
	ret.size = 0;
	ret.data = malloc(sizeof(T)*ret.cap);
	if (ret.data == NULL) {
		fprintf(stderr, "Error occured when allocating memory\n");
		exit(1);
	}
	return ret;
}

VT(vector) VT(initnp)(T *init, size_t size) {
	VT(vector) ret;
	ret.cap = VECT_THRESH;
	ret.cap = (ret.cap < size) ? (ret.cap * VECT_FACT) + size : ret.cap;
	ret.size = size;
	ret.data = malloc(sizeof(T) * ret.cap);
	if (ret.data == NULL) {
		fprintf(stderr, "Memory Allocation failed\n");
	}
	for (size_t i = 0; i < size; i++) {
		T val = init[i];
		ret.data[i] = val;
	}
	return ret;
}

VT(vector) VT(initp)(T *init) {
	return VT(initnp)(init, sizeof(init));
}

VT(vector) VT(subs)(VT(vector) *base, size_t first, size_t len) {
	VT(vector) ret = VT(initnp)(base->data+first, len);
	
	return ret;
}

void VT(append)(VT(vector) *vect, T elem) {
	if (vect->data != NULL) {
		if (vect->size + 1 >= vect->cap) {
			vect->cap *= VECT_FACT;
			vect->cap++;
			vect->data = realloc(vect->data, vect->cap*sizeof(T));
		}
		vect->data[vect->size++] = elem;
	}
}

void VT(free)(VT(vector) *vect) {
	#ifdef V_POINTER
	for (int i = 0; i < vect->size; i++) {
		vect->data[i] = NULL;
		free(vect->data[i]);
	}
	#endif
	free(vect->data);
	vect->data = NULL;
}

/* be careful when using this function */
/* you may put in the wrong position */
/* and end up allocating a LOT of useless memory */
/* as the position is offset by the size of the first */
/* vector */
void VT(join)(VT(vector) *vect, VT(vector) vect2, size_t pos) {
	if (vect->data != NULL && vect2.data !=  NULL) {
		if (vect->size + vect2.size + pos >= vect->cap) {
			vect->cap *= VECT_FACT;
			vect->cap += vect2.size + pos;
			vect->data = realloc(vect->data, vect->cap);
		}
		for (size_t i = 0; i < vect2.size; i++) {
			vect->data[(vect->size + pos) + i] = vect2.data[i];
		}
		vect->size += vect2.size;
		vect->size += pos;
	}
}

void VT(delete)(VT(vector) *vect, int index) {
	if (index <= vect->size) {
		#ifdef V_POINTER
		free(vect->data[index]);
		vect->data[index] = NULL;
		#endif
		for (int i = index; i < vect->size - 1; i++) {
			vect->data[i] = vect->data[i+1];
		}
		vect->size--;
	}
}

#ifdef V_POINTER
#undef V_POINTER
#endif

#undef VT
#undef T
#endif
