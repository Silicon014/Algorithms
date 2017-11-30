struct node {
	Elem elem;
	struct node * child;
	struct node * next;
	};
#include<stdio.h>
#include<stdlib.h>
#include"tree.h"
static void PrintElem(Elem e)
{
	printf(PRINT, e);
}
static Tree Find(Tree t, Elem e)
{
	
Tree CreateTree(void)
{
	Tree t;
	
	t = (Tree) malloc(sizeof(Node));
	return t;
}
void DeleteTree(Tree t)
{
	if (t->next != NULL)
		DeleteTree(t->next);
	if (t->child != NULL)
		DeleteTree(t->child);
	free(t);
	//树太大的话会导致栈耗尽，但是懒得考虑非递归了
}
int IsNull(Tree t)
{
	return t->child == NULL && t->next == NULL;
}
static void Print(Tree t, int depth)
{
	for (int i = depth; i > 0; --i)
		printf("\t");
	PrintElem(t->elem);
	putchar('\n');
	if (t->next != NULL)
		Print(t->next, depth);
	if (t->child != NULL)
		Print(t->child, depth + 1);
	//同样担心栈……
}
void PrintTree(Tree t)
{
	Print(t, 0);	//隐藏接口
}
