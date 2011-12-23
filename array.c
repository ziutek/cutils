#include <pthread.h>
#include <stdlib.h>

#include "array.h"

Array *newArray(int size, int cap, void *buf) {
	Array *a = Calloc(Array, 1);
	a->Cap = cap;
	a->size = size;
	a->ref = 1;
	a->buf = buf;
	return a;
}

Array *Array_Ref(Array *a) {
	++a->ref;
	return a;
}

void Array_Unref(Array *a) {
	if (--a->ref == 0) {
		free(a->buf);
		free(a);
	}
}

Slice Array_Slice(Array *a, int from, int to) {
	assert(0 <= from);
	assert(from <= to);
	assert(to <= a->Cap);
	Slice s = {to - from, a->Cap - from, a->buf + from * a->size, Array_Ref(a)};
	return s;
}


Slice newSlice(int len, int cap, Array *a) {
	assert(len >= 0);
	assert(len <= cap);
	Slice s = {len, cap, a->buf, a};
	return s;
}
