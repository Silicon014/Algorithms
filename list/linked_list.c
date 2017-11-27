#include<stdio.h>
#include<stdlib.h>
#include"list.h"

List CreateList(int i)
{
	List list;

	list = (List)malloc(sizeof(Node));
	list->next = NULL;
	return list;
}
int IsListEmpty(List list)
{
	return list->next == NULL;
}
int IsListFull(List list)
{
	Node * test = (List)malloc(sizeof(Node));
	if (test != NULL)
	{
		free(test);
		return 0;
	}
	else
		return 1;
}
List DeleteList(List list)
{
	Position p;

	do
	{
		p = list;
		list = list->next;
		free(p);
	}
	while (list != NULL);
	return NULL;
}
void Insert(List list, Position p, Elem e)
{
	Position m, n;

	m = (Position)malloc(sizeof(Node));
	n = p->next;
	p->next = m;
	m->next = n;
	m->elem = e;
}
void Add(List list, Elem e)
{
	Position p;

	p = (Position)malloc(sizeof(Node));
	p->elem = e;
	FindTail(list)->next = p;
}
Position Find(List list, Elem e)
{
	while (list->next != NULL && list->elem != e)
		list = list->next;
	if (list->elem == e)
		return list;
	else
		return NULL;
}
Position FindPrev(List list, Position p)
{
	while (list->next != NULL && list->next != p)
		list = list->next;
	if (list->next != NULL)
		return list;
	else
		return NULL;
}
Position FindTail(List list)
{
	while (list->next != NULL)
		list = list->next;
	return list;
}
