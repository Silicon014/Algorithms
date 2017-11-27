#include<stdio.h>
#include<stdlib.h>
#include"list.h"
int main(void)
{
	List nums;
	Item items;

	nums = list_init();
	items.value = 10;
	if (list_isempty(nums))
		list_add(nums, items);
	else
	{
		fprintf(stderr, "Error: list is not empty?\n");
		return 0;
	}
	list_print_all(nums);
	items.value = 5;
	printf("modified: %d\n", list_modify(nums, items, 1));
	list_print(nums, 1);
	list_makeempty(nums);
	list_free(nums);
	return 0;
}
