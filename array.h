#ifndef __ARRAY__
#define __ARRAY__

#include "common.h"

typedef struct Array Array;
struct Array {
	int Cap;
	int size; // Size of element
	int ref; // Reference counter.
	void *buf;
};

// Creates new zeroed Array of type Type. Array has refference semantic.
#define NewArray(Type, cap) \
	newArray(sizeof(Type), cap, Calloc(Type, cap))

// This method can be used to access to elemtnts of array:
// x = Array_Elem(a, int, 2); Array_Elem(a, int, 2) = x;
#define Array_Elem(a, Type, n) (*( \
			(Type *) a->buf + (assert(n >= 0), assert(n < a->Cap), \
				assert(sizeof(Type) == a->size), n) \
			))

// Returns new reference to a. Incrases reference counter.
Array *Array_Ref(Array *a);

// Decreases reference counter. Frees memory if counter == 0.
void Array_Unref(Array *a);


typedef struct Slice Slice;
struct Slice {
	int Len;
	int Cap;
	void *buf;
	Array *a;
};

// Return slice of array a. Incrases reference counter.
Slice Array_Slice(Array *a, int from, int to);

// Creates a slice of newly created array.
#define NewSlice(Type, len, cap) \
		newSlice(len, cap, NewArray(Type, cap)) \

#define Slice_Elem(s, Type, n) (*( \
			(Type *) s.buf + (assert(n >= 0), assert(n < s.Cap), \
				assert(sizeof(Type) == s.a->size), n) \
			))


// Private methods

Array *newArray(int size, int cap, void *buf); 
Slice newSlice(int len, int cap, Array *a);

#endif
