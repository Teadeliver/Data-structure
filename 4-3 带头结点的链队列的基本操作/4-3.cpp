
#include <stdio.h>
#include<malloc.h>
#define OK 1
#define ERROR 0
typedef int Status;
typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LNode, * LinkList;

typedef struct
{
	LinkList front, rear; /* ��ͷ����βָ�� */
}LinkQueue;
/* ��ͷ���������еĻ������� */
Status InitQueue(LinkQueue* Q)
{ /* ����һ���ն���Q */
	LinkList p;
	p = (LNode*)malloc(sizeof(LNode));
	p->next = NULL;
	(*Q).rear = (*Q).front = p;
	return OK;
}
Status List(LinkList L)
{
	LinkList p;
	if (!L) return ERROR;
	p = L->next;

	while (p)
	{
		printf(" %d", p->data);
		p = p->next;
	}
	printf("\n");
	return OK;
}

int QueueLenth(LinkQueue Q)
{
	int n = 0;
	LinkList p;
	if (Q.rear == Q.front)
		return 0;
	p = Q.front->next;
	while (p)
	{
		n++;
		p = p->next;
	}
	return n;
}

int main()
{
	int x;
	LinkQueue Q;
	InitQueue(&Q);
	QueueInsert(&Q, 1); QueueInsert(&Q, 2); QueueInsert(&Q, 3);
	List(Q.front);
	QueueDelete(&Q, &x);
	printf(" %d %d\n", x, QueueLenth(Q));
	QueueDelete(&Q, &x); QueueDelete(&Q, &x);
	printf(" %d %d\n", x, QueueLenth(Q));
	return 0;
}

/* ����������д�� */

Status QueueInsert(LinkQueue* Q, ElemType e)
{
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if (!s) /* �洢����ʧ�� */
		return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	/* ��ӵ��Ԫ��e���½��s��ֵ��ԭ��β���ĺ�� */
	Q->rear = s;		/* �ѵ�ǰ��s����Ϊ��β��㣬rearָ��s */
	return OK;
}

Status QueueDelete(LinkQueue* Q, ElemType* e)
{
	LinkList p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;		/* ����ɾ���Ķ�ͷ����ݴ��p */
	*e = p->data;				/* ����ɾ���Ķ�ͷ����ֵ��ֵ��e */
	Q->front->next = p->next;/* ��ԭ��ͷ���ĺ��p->next��ֵ��ͷ����� */
	if (Q->rear == p)		/* ����ͷ���Ƕ�β����ɾ����rearָ��ͷ��� */
		Q->rear = Q->front;
	free(p);
	return OK;
}