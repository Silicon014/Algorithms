#define TYPE int
typedef TYPE Element;
typedef struct node {
	Element ch;
	struct node * next;
	} Node;
typedef Node * Stack;
Stack CreateStack(void);	//创建一个栈
Stack MakeEmpty(Stack);		//初始化栈为空栈
Stack Push(Element, Stack);	//入栈
Stack Pop(Stack);		//出栈
Element Top(Stack);		//出栈
int IsEmpty(Stack);		//判断栈是否为空
int IsFull(Stack);		//判断栈是否已满
int Free(Stack);		//释放栈
