#ifndef _Tree_H
typedef double Elem;
struct tree {
	Elem elem;
	struct tree * left;
	struct tree * right;
	};
typedef struct tree * Tree;

#endif
