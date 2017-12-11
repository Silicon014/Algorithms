#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
//内部链接的基本函数
static void Pop(Stack s)
{
	Node * tmp = s->top;
	s->top = s->top->next;
	free(tmp);
}
static Elem Top(Stack s)
{
	return stack->top->elem;
}
static void Push(Stack s, Elem e)
{
	Node * tmp = (Node *)malloc(sizeof(Node));
	tmp->elem = e;
	tmp->next = s->top;
	s->top = tmp;
}
inline void Free(Stack s)
{
	if s->next != NULL
		Free(s->next);
	else
		free(s);
}
