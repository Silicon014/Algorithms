typedef double Elem;
#define PRINT "%.2lf\n"
typedef struct node TreeNode;
typedef TreeNode * Tree;
typedef TreeNode * Root;

Root Find(Tree t, Elem e);	//查找
Tree CreateTree(void);		//新建树
void DeleteTree(Tree t);	//删除树
int IsNull(Root r);		//是否为空
void PrintTree(Tree t);		//打印树
