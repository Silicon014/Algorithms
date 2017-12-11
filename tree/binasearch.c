//头文件
#include<stdio.h>
#include<stdlib.h>
#include"binasearch.h"

/*函数*/

inline void Free(Tree t)
{
	  if (t != NULL)
	  {
		    MakeEmpty(t->l);
		    MakeEmpty(t->r);
		    free(t);
	  }
	  else
	  {
		    free(t);
	  }
}
static int cmpint(Elem a, Elem b)
{
	  if (a.i == b.i)
		    return 0;
	  else
		    return a.i - b.i;
}
static int cmpdouble(Elem a, Elem b)
{
	  if (a.d == b.d)
		    return 0;
	  else
		    return (int)(a.d - b.d);
}
inline Tree FindInt(Tree t, Elem e)
{
	  int i = cmpint(t->elem, e);
	  if (i > 0)
		    return FindInt(t->r, e);
	  else
	  {
		    if (i < 0)
				return FindInt(t->l, e);
		    else
				return t;
	  }
	  return NULL;
}
/*封装好的函数*/
Tree MakeEmpty(Tree t)
{
	  if (t != NULL)
	  {
		    Free(t);
		    return NULL;
	  }
	  else
		    return NULL;
}
