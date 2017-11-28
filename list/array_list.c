#include<stdio.h>
#include<stdlib.h>
typedef int Elem;
typedef struct node {
	Elem elem;
	} Node;
#include"list.h"
List CreateList(int n)
{
	List list;

	list = (List)malloc(sizeof(Node) * n);
	return List;
}
int IsListEmpty(List list)
{
	fprintf(stderr, "Warning: cannot judge"
		" if a array-list is empty."
		" defaultly returns 1\n");
	return 1;
}
int IsListFull(List list)
{
	fprintf(stderr, "Warning: cannot judge if a array-list is full."
		" defaultly returns 1\n");
	return 1;
}
int IsLast(Position p, List list)
{
	fprintf(stderr, "Warning: cannot judge if a position in an"
		" array-list is last. defaultly returns 1\n");
	return 1;
}
List DeleteList(List list)
{
	free(list);
	return NULL;
}
void Insert(List list, Position p, Elem e)
{
	p->elem = e;
}
void Add(List list, Elem e)
{
	fprintf(stderr, "warning: not a safe operate\n");
	list[0]->elem = e;
}
Position Find(List list, Elem e)
{
	
Position FindPrev(List, Position);
Position FindTail(List);

