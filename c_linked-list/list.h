struct item {
	int value;
	};
/*item是一个结构。（*/
typedef struct item Item;
//重定义类型名struct item为Item
typedef struct node {
	Item item;
	struct node * next;
	} Node;
//定义并命名类型Node
typedef Node * List;
//重命名类型Node *为List
/*
 *	List is the name of ADT "list".
 *	it is the pointer to "Node".
 *	
 *	Node is a node of lined-list List.
 *	it is a struct which contents a Item "item",
 *	and a pointer of struct node "next".
 *	
 *	Item is a struct.
 *	it contents only int "value".
 */

List list_init(void);	//create a empty linked-list, return the value of the linked-list.
/*函数list_init()
 *功能：创建一个空链表
 *返回值：链表
 */
int list_isempty(List);	//judge if a linked-list is empty (only contents header node), return 0 if it's not empty
/*函数list_isempty()
 *功能：判断链表是否是空链表
 *参数：链表
 *返回值：结果为真，返回真；结果为假，返回假
 */
int list_isfull(List);	//judge if a list is full (cannot create a new node), return 0 if it's not full
/*函数list_isfull()
 *功能：判断链表是否已满（是否可以添加新项）
 *参数：链表
 *返回值：真/假
 */
int list_node_count(List);	//count the nodes of a list (not include the header), return the result
/*函数list_node_count()
 *功能：计数链表中共有多少项
 *参数：链表
 *返回：计算结果
 */
List list_add(List, Item);	//create a new node at the end of a list, contents the "item", return the list
/*函数：list_add()
 *功能：向链表中添加新的一项，项内含一类型为Item的数据
 *参数：链表，项内容
 *返回：链表
 */
List list_makeempty(List);	//delete all nodes of a list (not include the header), return the new node
/*函数：list_makeempty()
 *功能：清空链表中的所有项，得到一个空链表
 *参数：链表
 *返回：链表
 */
int list_search(List, Item);	//search and return the node contents Item, 0 if not found
/*函数：list_search()
 *功能：在链表中搜索指定内容，得出其位于链表的第几项
 *参数：链表，项内容
 *返回：项数
 */
int list_modify(List, Item, int);	//modify the node with the item , return the node
/*函数：list_modify()
 *功能：在链表中用指定的内容替换指定项的内容
 *参数：链表，项内容，项数
 *返回：修改的位置
 */
int list_print(List, int);	//print the item of the node, return the node
/*函数：list_print()
 *功能：打印链表中指定项的内容
 *参数：链表，项数
 *返回值：打印的位置
 */
void list_free(List);	//free the list
/*函数：list_free()
 *功能：删除链表
 *参数：链表
 *返回值：无
 */
List list_print_all(List);	//print all contents
/*函数：list_print_all()
 *功能：按顺序打印链表中的所有项
 *参数：链表
 *返回值：链表
 */
void item_print(Item);	//print Item
/*函数：item_print()
 *功能：打印一个Item类型的数据
 *参数：Item类型的数据
 *返回：无
 */
int item_isequal(Item, Item);	//judge if two struct "Item" is squal
/*函数：item_isequal()
 *判断两个Item类型的值是否相等，返回真/假
 */
