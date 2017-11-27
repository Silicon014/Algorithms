#include<stdlib.h>
#include<stdio.h>
#include"list.h"

List list_init(void)
{
	List header;

	header = (List)malloc(sizeof(Node));
	header->next = NULL;
	return header;
}
int list_isempty(List list)
{
	return list->next == NULL;
}
int list_isfull(List list)
{
	List test;

	if ((test = (List)malloc(sizeof(Node))) != NULL)
	{
		free(test);
		return 0;
	}
	else
		return 1;
}
int list_node_count(List list)
{
	int i;
	
	for (i = 0; list->next != NULL; ++i)
		list = list->next;
	return i;
}
List list_add(List list, Item items)
{
	List node;
	
	if (list_isfull(list))
	{
		fprintf(stderr, "Error: list is full\n");
		return NULL;
	}
	node = (List)malloc(sizeof(Node));
	node->next = NULL;
	node->item = items;
	while (list->next != NULL)
		list = list->next;
	list->next = node;
	return node;
}
List list_makeempty(List list)
{
	List cleaner, searcher;

	if (list_isempty(list))
		return list;
	else
	{
		searcher = list->next;
		do
		{
			cleaner = searcher;
			searcher = searcher->next;
			free(cleaner);
		}
		while (searcher);
	}
	return list;
}
int list_search(List list, Item items)
{
	if (list_isempty(list))
	{
		fprintf(stderr, "Warning: list is empty\n");
		return 0;
	}
	for (int i = 1; list->next != NULL; ++i)
	{
		if (item_isequal(list->next->item, items))
			return i;
		else
			list = list->next;
	}
	return 0;
}
int list_modify(List list, Item items, int n)
{
	if (list_isempty(list))
	{
		fprintf(stderr, "Warning: list is empty\n");
		return 0;
	}
	for (int i = 0; i < n; ++i)
	{
		if (list->next == NULL)
		{
			fprintf(stderr, "Error: Node override\n");
			return i + 1;
		}
		else
			list = list->next;
	}
	list->item = items;
	return n;
}
int list_print(List list, int n)
{
	for (int i = 0; i < n; ++i)
	{
		if (list->next == NULL)
		{
			fprintf(stderr, "Error: Node override\n");
			return i + 1;
		}
		else
			list = list->next;
	}
	item_print(list->item);
	return n;
}
void list_free(List list)
{
	List cleaner;

	do
	{
		cleaner = list;
		list = list->next;
		free(cleaner);
	}
	while (list);
}
List list_print_all(List list)
{
	List searcher;

	searcher = list;
	do
	{
		item_print(searcher->item);
		searcher = searcher->next;
	}
	while (searcher);
	return list;
}
void item_print(Item items)
{
	printf("%d\n", items.value);
}
int item_isequal(Item item1, Item item2)
{
	return item1.value == item2.value;
}
