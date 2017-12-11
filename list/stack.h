//栈ADT
typedef union {
	int i;
	double d;
	char c;
} Elem;//栈中的数据
typedef struct node {
	Elem elem;
	struct node * next;
} Node;
typedef struct Node * Stack;//栈ADT

//函数

