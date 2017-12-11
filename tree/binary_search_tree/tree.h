#ifndef __TREE_H__
#define __TREE_H__
typedef int Elem; //元素
typedef struct tree_node {
    Elem elem;  //元素
    struct tree_node * left; //左子树
    struct tree_node * right;//右子树
} Tree; //树ADT
typedef Tree Position; //表示一棵树中间的某个位置
typedef Tree Node;     //表示一个树节点
//函数列表
//初始化、删除树：
Tree MakeEmpty(
//Find：
Position Find(Elem, Tree); //找到树中包括元素的位置
Position FindMin(Tree); //找到树中最小元素的位置
Position FindMax(Tree); //找到树中最大元素的位置
#endif
