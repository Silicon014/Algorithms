#include<stdio.h>
#include"stack.h"
#define NUM 1000
#define CHAR 'a'
char get_a_char(void)
{
	char ch;
	
	scanf("%c", &ch);
	while (getchar() != '\n')
		continue;
	return ch;
} 
Stack push_some_chars(Stack s, int i, char c);
int main(void)
{
	Stack test;

//	printf("Before Null: %s\n", (IsEmpty(test))? "true": "false");
//	printf("Before Create: %s\n", (IsEmpty(test = NULL))?"true":"false");
	printf("After Create: %s\n", (IsEmpty(test = CreateStack()))? "true": "false");
	printf("After Make: %s\n", (IsEmpty(test = MakeEmpty(test)))? "true": "false");

	printf("Top of Empty Stack: %c\n", Top(test));
	printf("Pop a Empty stack, it should print \"Error: stack is empty\":\n");
	printf("Originly it is %p, now it returns %p\n", test, Pop(test));
	
	printf("Now it will scan a char and push it into the stack:\nenter a char: ");
	printf("Now the stack is %p.\n", test = Push(get_a_char(), test));
	printf("Top of the stack now: %c\n", Top(test));
	printf("Now pop the stack. It backed to %p\n", test = Pop(test));
	
	printf("Now push %d \"%c\" into the stack.\n", NUM, CHAR);
	printf("Now the value of stack is %p. ", test = push_some_chars(test, NUM, CHAR));
	printf("the Top of stack is %c.\n", Top(test));

	printf("Is the stack full now? %s\n", (IsFull(test))?"yes":"no");
	printf("Now free the stack.\n");
	printf("Freed: %d\n", Free(test));
	
	return 0;
}
inline Stack push_some_chars(Stack s, int i, char c)
{
	for (int j = 0; j < i; ++j)
	{
		s = Push(c, s);
	}
	return s;
}
