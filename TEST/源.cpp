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
��������L��5������, �ֱ��� 10, 20, 30, 40, 50
λ�÷�Χ�Ǵӵ�1λ����5λ.

����Ҫ�ҵ�6��Ԫ��(���),j = 5�Ѿ�������Χ.
ִ�����while(p && j < i - 1)֮��, ��ʱ, i, j, p����ֵ�ֱ���:
i = 6, j = 5, p���ڿ�ָ��(NULL),
Ҳ����p����0, ��!p����1(����true, ��)
���� !p����, j > i-1�Ǽ�, ���� if (!p || j > i - 1) ������,
����, ִ��return ERROR

����Ҫ�ҵ�0��Ԫ��(���), ���Կ���, i = 0������Χ.
ִ�����while(p && j < i-1)֮��, ��ʱ, i, j, p����ֵ�ֱ���:
i = 0, j = 0, 
p���ڵ�1������ָ��, p������0, ��!p����0(����false, ��)
���� !p�Ǽ�, j > i-1����, ���� if (!p || j > i-1) ������,
����ִ��return ERROR
//typedef int ElemType;
//typedef int Status;
//
//typedef struct LNode
//{
//	ElemType data;
//	struct LNode* next;
//}LNode, * LinkList;
//
////��������
//void CreateList(LinkList& L, int n)
//{
//	LinkList newNode; //�½��
//	LinkList ptr;     //��ǰ���
//	int i;
//
//	//���Ǵ�ͷ���ĵ�����
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
////��ӡ����
//void DispList(LinkList L)
//{
//	LinkList ptr;     //��ǰ���
//	ptr = L->next;
//	if (ptr == NULL)
//	{
//		printf("����û������.\n");
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
////���ҵ�i�����
//Status GetElem(LinkList L, int i, ElemType& e) // �㷨2.8
//{
//	// LΪ��ͷ���ĵ������ͷָ�롣����i��Ԫ�ش���ʱ����ֵ����e������OK�����򷵻�ERROR
//	int j = 1; // jΪ������
//
//	LinkList p = L->next; // pָ���һ�����
//
//	while (p && j < i) // ˳ָ�������ң�ֱ��pָ���i��Ԫ�ػ�pΪ��
//	{
//		p = p->next;
//		j++;
//	}
//
//	////////����
//	if (p == NULL)
//	{
//		printf("\n����: i=%d, j=%d, p=%p, !p=%x\n", i, j, p, !p);
//	}
//	else
//	{
//		printf("\n����: i=%d, j=%d, p=%p, !p=%x, e=%d\n", i, j, p, !p, p->data);
//	}
//	////////
//
//	if (!p || j > i) // ��i��Ԫ�ز�����
//	{
//		return ERROR;
//	}
//
//	e = p->data; // ȡ��i��Ԫ��
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
//	printf("�������������: ");
//	DispList(L);
//
//	i = 6;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("��%dλ��������ķ�Χ.\n", i);
//	}
//	else
//	{
//		printf("�� %d ������� %d\n", i, e);
//	}
//
//	i = 0;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("��%dλ��������ķ�Χ.\n", i);
//	}
//	else
//	{
//		printf("��%d������� %d\n", i, e);
//	}
//
//	i = 3;
//	ret = GetElem(L, i, e);
//	if (ret == ERROR)
//	{
//		printf("��%dλ��������ķ�Χ.\n", i);
//	}
//	else
//	{
//		printf("��%d������� %d\n", i, e);
//	}
//
//	return 0;
//}