
//二叉查找树
//数据结构算法
#ifndef _BINATREE_H_
typedef union element {
	  char c;
	  int i;
	  double d;
} ELem;
struct treenode {
	  Elem elem;
	  struct treenode * l;
	  struct treenode * r;
};
typedef treenode * Tree;
#endif
