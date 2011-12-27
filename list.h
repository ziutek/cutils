#ifndef __LIST__
#define __LIST__

#include "common.h"

typedef struct ListElem ListElem;
typedef struct List List;

struct ListElem {
	ListElem *Prev, *Next;
	List *List;
	void *Value;
};

struct List {
	ListElem *Front, *Back;
	int Len;
};

List *NewList();
void *List_Remove(List *l, ListElem *e);
ListElem *List_PushFront(List *l, void *value);
ListElem *List_PushBack(List *l, void *value);
ListElem *List_InsertBefore(List *l, void *value, ListElem *mark);
ListElem *List_InsertAfter(List *l, void *value, ListElem *mark);
void List_MoveToFront(List *l, ListElem *e);
void List_MoveToBack(List *l, ListElem *e);

#endif // __LIST__
