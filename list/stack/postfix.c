#define TYPE int
#define PRINT "%d\n"

#include<stdio.h>
#include<ctype.h>
#include"stack.h"

Stack selector(Element, Stack);
Stack put_together(Stack);
Stack Addition(Stack);
Stack Subtraction(Stack);
Stack Multiply(Stack);
Stack Division(Stack);
Element ctoe(Element);

typedef TYPE Element;
int main(void)
{
	Stack s;
	Element c;

	s = CreateStack();
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
	x1 = ctoe(Top(s));
	s = Pop(s);
	if ((x2 = Top(s)) == 0)
	{
		s = Push(x1, s);
		return s;
	}
	s = Pop(s);

	//计算并写入结果
	s = Push(x2 * 10 + x1, s);
	
	return s;
}
Stack Addition(Stack s)
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
Stack Subtraction(Stack s)
{
	Element x1, x2;

	s = Pop(s);
	x1 = Top(s);
	s = Pop(s);
	x2 = Top(s);
	s = Pop(s);

	s = Push(x2 - x1, s);

	return s;
}
Stack Multiply(Stack s)
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
Stack Division(Stack s)
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
Element ctoe(Element i)
{
	char ch;

	ch = (char)i;
	switch (ch)
	{
		case '0':
			return (Element)0;
		case '1':
			return 1;
		case '2':
			return 2;
		case '3':
			return 3;
		case '4':
			return 4;
		case '5':
			return 5;
		case '6':
			return 6;
		case '7':
			return 7;
		case '8':
			return 8;
		case '9':
			return 9;
		default:
			break;
	}
	fprintf(stderr, "ctoe error, default 0\n");
	return 0;
}
