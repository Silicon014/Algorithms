typedef int Elem;
typedef struct node {
	Elem element;
	struct node * next;
	} Node;
typedef Node * List;
typedef Node * Position;

List CreateList(int);		//创建表
int IsListEmpty(List);		//判断表是否为空
int IsListFull(List);		//判断表是否为满
int IsLast(Position, List);	//判断是否为表的尾端

List DeleteList(List);		//删除表
void Insert(List, Position, Elem);	//插入节点
void Add(List, Elem);		//添加节点

Position Find(List, Elem);	//查找单元
Position FindPrev(List, Position);
Position FindTail(List);	//查找尾节点

