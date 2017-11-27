#include<stdio.h>
#include"stack.h"
Stack get_infix(void)
{
	Stack s;
	char ch;
	
	s = CreateStack();
	s = MakeEmpty(s);
	while ((ch = getchar()) != '\n')
		s = Push((Element)ch, s);
	return s;
}
	
