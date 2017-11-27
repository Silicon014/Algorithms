#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include"postfix.h"

int main(void)
{
	Stack s;
	char c;

	s = CreateStack(s);
	while ((c = getchar()) != '\n')
	{
		s = Push(c, s);
		selector(Top(s), s);
	}
	
	
