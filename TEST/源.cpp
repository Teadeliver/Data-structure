#include<stdio.h>
#include<stdlib.h>

#define OVERFLOW -1
#define ERROR     0
#define OK        1

int main()
{
	int i, j;
	j = 0, i = 5;
	for (;j<i-1;)
	{
		printf("%d ", j);
		++i;
	}
}
假设链表L有5个数据, 分别是 10, 20, 30, 40, 50
位置范围是从第1位到第5位.

假设要找第6个元素(结点),j = 5已经超出范围.
执行语句while(p && j < i - 1)之后, 此时, i, j, p的数值分别是:
i = 6, j = 5, p等于空指针(NULL),
也就是p等于0, 而!p等于1(这是true, 真)
由于 !p是真, j > i-1是假, 满足 if (!p || j > i - 1) 的条件,
所以, 执行return ERROR

假设要找第0个元素(结点), 可以看到, i = 0超出范围.
执行语句while(p && j < i-1)之后, 此时, i, j, p的数值分别是:
i = 0, j = 0, 
p等于第1个结点的指针, p不等于0, 而!p等于0(这是false, 假)
由于 !p是假, j > i-1是真, 满足 if (!p || j > i-1) 的条件,
所以执行return ERROR
//typedef int ElemType;
//typedef int Status;
//
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//}LNode, * LinkList;
//
////创建链表
//void CreateList(LinkList& L, int n)
//{
//	LinkList newNode; //新结点
//	LinkList ptr;     //当前结点
//	int i;
//
//	//这是带头结点的单链表
//	L = (LinkList)malloc(sizeof(LNode));
//	L->next = NULL;
//	ptr = L;
//
//	for (i = 0; i < n; i++)
//	{
//		newNode = (LinkList)malloc(sizeof(LNode));
//		newNode->data = (i + 1) * 10;
//		newNode->next = NULL;
//		ptr->next = newNode;
//		ptr = newNode;
//	}
//}
//
////打印链表
//void DispList(LinkList L)
//{
//	LinkList ptr;     //当前结点
//	ptr = L->next;
//	if (ptr == NULL)
//	{
//		printf("链表没有数据.\n");
//		return;
//	}
//	while (ptr != NULL)
//	{
//		printf("%d ", ptr->data);
//		ptr = ptr->next;
//	}
//	printf("\n");
//}
//
////查找第i个结点
//Status GetElem(LinkList L, int i, ElemType& e) // 算法2.8
//{
//	// L为带头结点的单链表的头指针。当第i个元素存在时，其值赋给e并返回OK，否则返回ERROR
//	int j = 1; // j为计数器
//
//	LinkList p = L->next; // p指向第一个结点
//
//	while (p && j < i) // 顺指针向后查找，直到p指向第i个元素或p为空
//	{
//		p = p->next;
//		j++;
//	}
//
//	////////测试
//	if (p == NULL)
//	{
//		printf("\n测试: i=%d, j=%d, p=%p, !p=%x\n", i, j, p, !p);
//	}
//	else
//	{
//		printf("\n测试: i=%d, j=%d, p=%p, !p=%x, e=%d\n", i, j, p, !p, p->data);
//	}
//	////////
//
//	if (!p || j > i) // 第i个元素不存在
//	{
//		return ERROR;
//	}
//
//	e = p->data; // 取第i个元素
//
//	return OK;
//}
//
//int main()
//{
//	LinkList L;
//	int i;
//	ElemType e;
//	Status ret;
//
//	CreateList(L, 5);
//
//	printf("链表里的数据有: ");
//	DispList(L);
//
//	i = 6;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("第%d位超出链表的范围.\n", i);
//	}
//	else
//	{
//		printf("第 %d 个结点是 %d\n", i, e);
//	}
//
//	i = 0;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("第%d位超出链表的范围.\n", i);
//	}
//	else
//	{
//		printf("第%d个结点是 %d\n", i, e);
//	}
//
//	i = 3;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("第%d位超出链表的范围.\n", i);
//	}
//	else
//	{
//		printf("第%d个结点是 %d\n", i, e);
//	}
//
//	return 0;
//}