#include "list.h"

List *NewList() {
	return Calloc(List, 1);
}

void List_remove(List *l, ListElem *e) {
	assert(e->List == l);
	if (e->Prev == NULL) {
		l->Front = e->Next;
	} else {
		e->Prev->Next = e->Next;
	}
	if (e->Next == NULL) {
		l->Back = e->Prev;
	} else {
		e->Next->Prev = e->Prev;
	}
	e->Prev = e->Next = NULL;
	--l->Len;
}

void *List_Remove(List *l, ListElem *e) {
	List_remove(l, e);
	void *v = e->Value;
	Free(e);
	return v;
}

void List_insertBefore(List *l, ListElem *e, ListElem *mark) {
	if (mark->Prev == NULL) {
		l->Front = e;
	} else {
		mark->Prev->Next = e;
	}
	e->Prev = mark->Prev;
	mark->Prev = e;
	e->Next = mark;
	++l->Len;
}

void List_insertAfter(List *l, ListElem *e, ListElem *mark) {
	if (mark->Next == NULL) {
		l->Back = e;
	} else {
		mark->Next->Prev = e;
	}
	e->Next = mark->Next;
	mark->Next = e;
	e->Prev = mark;
	++l->Len;
}

void List_insertFront(List *l, ListElem *e) {
	if (l->Front == NULL) {
		l->Front = l->Back = e;
		e->Prev = e->Next = NULL;
		l->Len = 1;
		return;
	}
	List_insertBefore(l, e, l->Front);
}

void List_insertBack(List *l, ListElem *e) {
	if (l->Back == NULL) {
		l->Front = l->Back = e;
		e->Prev = e->Next = NULL;
		l->Len = 1;
		return;
	}
	List_insertAfter(l, e, l->Back);
}

ListElem *List_PushFront(List *l, void *value) {
	ListElem *e = Malloc(ListElem, 1);
	e->Prev = e->Next = NULL;
	e->List = l;
	e->Value = value;
	List_insertFront(l, e);
	return e;
}

ListElem *List_PushBack(List *l, void *value) {
	ListElem *e = Malloc(ListElem, 1);
	e->Prev = e->Next = NULL;
	e->List = l;
	e->Value = value;
	List_insertBack(l, e);
	return e;
}

ListElem *List_InsertBefore(List *l, void *value, ListElem *mark) {
	assert(mark->List == l);
	ListElem *e = Malloc(ListElem, 1);
	e->Prev = e->Next = NULL;
	e->List = l;
	e->Value = value;
	List_insertBefore(l, e, mark);
	return e;
}

ListElem *List_InsertAfter(List *l, void *value, ListElem *mark) {
	assert(mark->List == l);
	ListElem *e = Malloc(ListElem, 1);
	e->Prev = e->Next = NULL;
	e->List = l;
	e->Value = value;
	List_insertAfter(l, e, mark);
	return e;
}

void List_MoveToFront(List *l, ListElem *e) {
	assert(e->List == l);
	if(l->Front == e) {
		return;
	}
	List_remove(l, e);
	List_insertFront(l, e);
}

void List_MoveToBack(List *l, ListElem *e) {
	assert(e->List == l);
	if(l->Back == e) {
		return;
	}
	List_remove(l, e);
	List_insertBack(l, e);
}
