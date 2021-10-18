#include "stdio.h"

typedef double LELEMENT;
typedef struct LNode
{
	LELEMENT data;
	struct LNode* next;
}LNODE;

typedef struct L
{
	int length;
	LNODE* head;
}LLIST;

int LElementEq(const LELEMENT* x, const LELEMENT* y);

void LListUnique(LLIST* list)
{
	/*
	思路就是通过cur遍历整个链表，
	cur每到一个节点，
	就用next去遍历cur后面的节点，
	查看是否有节点的数据和cur指向的节点的数据相同，
	如果相同，就通过pre删除这个相同数据的节点
	直到next遍历完cur后的每一个节点，cur才会再向后遍历
	*/
	LNODE* cur = list->head->next;//cur指向链表有数据的第一个节点
	LNODE* pre = NULL;
	LNODE* next = NULL;
	while (NULL != cur) //cur不为空就循环
	{
		pre = cur;//pre的作用是方便删除节点，pre指向next指向的节点的前一个
		next = cur->next;//next的作用是用来遍历整个链表
		while (NULL != next) {
			if (LElementEq(&cur->data, &next->data))//LElementEq就是题目规定的用来判断值是否相等的函数
			{
				//如果cur指向节点的数据和next指向的节点的数据相同
				pre->next = next->next;/* pre指向next指向节点的前一个节点，
									   所以这行代码可以让next指向的节点从链表中删除 */
				list->length--;//删除一个节点后，链表长度相应减1
			}
			else
			{
				//如果cur指向节点的数据和next指向的节点的数据不相同
				pre = next;//这句代码相当于pre向后移动一个节点
			}
			next = next->next;//next指向下一个节点
		}
		cur = cur->next;//cur指向下一个节点
	}
}

int main()
{

}