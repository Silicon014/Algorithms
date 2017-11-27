#include<stdio.h>
#include<stdlib.h>
#include"stack.h"

Stack CreateStack(void)
{
	return (Stack)malloc(sizeof(Node));
}
Stack MakeEmpty(Stack s)
{
	s->next = NULL;
	return s;
}
Stack Push(char c, Stack s)
{
	Stack i;

	i = (Stack)malloc(sizeof(Node));
	i->ch = c;
	i->next = s;
	return i;
}
Stack Pop(Stack s)
{
	Stack i;

	if (IsEmpty(s))
	{
		fprintf(stderr, "Error: Stack is empty\n");
		return s;
	}
	i = s->next;
	free(s);
	return i;
}
char Top(Stack s)
{
	return s->ch;
}
int IsEmpty(Stack s)
{
	return !s->next;
}
int IsFull(Stack s)
{
	char * c;

	if ((c = (char *)malloc(sizeof(Node))))
	{
		free(c);
		return 0;
	}
	else
		return 1;
}
int Free(Stack s)
{
	Stack i;
	int a = 0;

	do
	{
		i = s;
		s = s->next;
		free(i);
		a++;
	}
	while (s);
	return a;
}
