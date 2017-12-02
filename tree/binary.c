#include<stdio.h>
#include<stdib.h>
#include"binary.h"

void MakEmpty(Tree t)
{
	if (t != NULL)
	{
		MakeEmpty(t->left);
		MakeEmpty(t->right);
		free(t);
	}
	return NULL;
}

