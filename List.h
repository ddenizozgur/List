#ifndef LIST_HEADER_GUARD
#define LIST_HEADER_GUARD
#include <stdint.h>

typedef struct List
{
	struct List *prev;
	void *data;
	struct List *next;
} List;

List *ListCreate(void *data);
size_t ListSize(List *root);
int ListInsert(List *pred, void *data);
int ListRemove(List **_link);
int ListPushBack(List **_root, void *data);
int ListPushFront(List **_root, void *data);
int ListPopBack(List **_root);
int ListPopFront(List **_root);
int ListDelete(List **_root);

#endif//LIST_HEADER_GUARD