#include "array.h"

int main(void) {
	LogFile = stderr;

	int n = 1000;
	Array *b = NewArray(int, n);
	Array *a = Array_Ref(b); 

	Array_Unref(b);

	for (int i = 0; i < a->Cap; ++i) {
		Array_Elem(a, int, i) = -i;
		assert(Array_Elem(a, int, i) == -i);
	}

	int start = 10;
	Slice s = Array_Slice(a, start, n - 10);

	for (int i = 0; i < s.Cap; ++i) {
		assert(Array_Elem(a, int, i + start) == Slice_Elem(s, int, i));
	}

	return 0;
}
