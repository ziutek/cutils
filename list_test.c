#include <unistd.h>
#include "list.h"

int main(void) {
	LogFile = stderr;

	ssize_t vals[] = {-1, 2, -3, 4, -5, 6, -7, 8, -9, 0};

	List *l = NewList();

	for (int i = 0; i < sizeof(vals)/sizeof(ssize_t); ++i) {
		List_PushBack(l, (void *) vals[i]);
	}
	int i = 0;
	for (ListElem *e = l->Front; e != NULL; e = e->Next) {
		assert((ssize_t) e->Value == vals[i]);
		++i;
	}

	return 0;
}
