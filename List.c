#include <stdlib.h>
#include "List.h"

List *ListCreate(void *data)
{
	if (data == NULL)
		return NULL;
	List *root = (List *)malloc(sizeof(List));
	if (root == NULL)
		return NULL;

	root->next = root->prev = root;
	root->data = data;
	return root;
}

size_t ListSize(List *root)
{
	if (root == NULL)
		return 0UL;

	size_t size = 0UL;
	List *temp = root;
	do {
		size++;
		temp = temp->next;
	} while (temp != root);
	return size;
}

int ListInsert(List *pred, void *data)
{
	if (pred == NULL || data == NULL)
		return -1;

	List *node = ListCreate(data);
	List *next = pred->next;
	pred->next = node;
	node->next = next;
	node->prev = pred;
	next->prev = node;
	return 0;
}

int ListRemove(List **_link)
{
	if (*_link == NULL)
		return -1;
	if (*_link == (*_link)->next) {
		free(*_link);
		*_link == NULL;
		return 0;
	}

	List *next = (*_link)->next;
	List *prev = (*_link)->prev;
	free(*_link);
	*_link == NULL;
	prev->next = next;
	next->prev = prev;
	return 0;
}

int ListPushBack(List **_root, void *data)
{
	if (data == NULL)
		return -1;
	if (*_root == NULL) {
		*_root = ListCreate(data);
		return 0;
	}

	return ListInsert((*_root)->prev, data);
}

int ListPushFront(List **_root, void *data)
{
	if (data == NULL)
		return -1;
	if (*_root == NULL) {
		*_root = ListCreate(data);
		return 0;
	}

	ListInsert((*_root)->prev, data);
	*_root = (*_root)->prev;
	return 0;
}

int ListPopBack(List **_root)
{
	return ListRemove(&(*_root)->prev);
}

int ListPopFront(List **_root)
{
	List *next = (*_root)->next;
	int res = ListRemove(_root);
	*_root = next;
	return res;
}

int ListDelete(List **_root)
{
	if (*_root == NULL)
		return -1;
	if (*_root == (*_root)->next) {
		free(*_root);
		*_root = NULL;
		return 0;
	}

	List *temp = *_root;
	do {
		List *next = temp->next;
		free(temp);
		temp = next;
	} while (temp != *_root);
	*_root = NULL;
	return 0;
}