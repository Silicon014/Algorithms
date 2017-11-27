typedef char Elem;
typedef struct node {
	Elem elem;
	struct node * next;
	} Node;
typedef Node * Queue;
Queue CreateQueue(int);		//创建队列
Queue EnQueue(Elem, Queue);	//入队
Queue DeQueue(Queue);		//出队
Queue IsEmpty(Queue);		//是否为空
Queue IsFull(Queue);		//是否为满
Queue Free(Queue);		//释放队列
