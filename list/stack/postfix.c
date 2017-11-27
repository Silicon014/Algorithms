#define TYPE int
#define PRINT "%d\n"

#include<stdio.h>
#include<stdlib.h>
#include"stack.h"
#include<ctype.h>
#include"postfix.h"

typedef TYPE Element;
int main(void)
{
	Stack s;
	Element c;

	s = CreateStack(s);
	while ((c = (Element)getchar()) != (Element)'\n')
	{
		s = Push(c, s);
		s = selector(Top(s), s);
	}
	printf(PRINT, Top(s));
	Free(s);
	return 0;
}
Stack selector(Element i, Stack s)
{
	if (isspace((char)i))
	{
		s = Pop(s);
		return s;
	}
	if (isdigit((char)i))
		s = put_together(s);
	else
		switch ((char)i)
		{
			case '+':
				s = Addition(s);
				break;
			case '-':
				s = Subtraction(s);
				break;
			case '*':
				s = Multiply(s);
				break;
			case '/':
				s = Division(s);
			default:
				break;
		}
	return s;
}
Stack put_together(Stack s)
{
	Element x1, x2;
	
	//读取
	x1 = Top(s);
	s = Pop(s);
	x2 = Top(s);
	s = Pop(s);

	//计算并写入结果
	s = Push(x1 * 10 + x2, s);
	
	return s;
}
Stack Addition(s)
{
	Element x1, x2;

	s = Pop(s);
	x1 = Top(s);
	s = Pop(s);
	x2 = Top(s);
	s = Pop(s);

	s = Push(x1 + x2, s);
	
	return s;
}
Stack Subtraction(s)
{
	Elment x1, x2;

	s = Pop(s);
	x1 = Top(s);
	s = Pop(s);
	x2 = Top(s);
	s = Pop(s);

	s = Push(x2 - x1, s);

	return s;
}
Stack Multiply(s)
{
	Element x1, x2;

	s = Pop(s);
	x1 = Top(s);
	s = Pop(s);
	x2 = Top(s);
	s = Pop(s);

	s = Push(x1 * x2, s);

	return s;
}
Stack Division(s)
{
	Element x1, x2;

	s = Pop(s);
	x1 = Top(s);
	s = Pop(s);
	if (x1 == 0)
	{
		fprintf(stderr, "Error: division 0\n");
		return s;
	}
	x2 = Top(s);
	s = Pop(s);

	s = Push(x2 / x1, s);

	return s;
}

