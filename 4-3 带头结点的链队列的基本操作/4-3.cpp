
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
	LinkList front, rear; /* 队头、队尾指针 */
}LinkQueue;
/* 带头结点的链队列的基本操作 */
Status InitQueue(LinkQueue* Q)
{ /* 构造一个空队列Q */
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

/* 请在这里填写答案 */

Status QueueInsert(LinkQueue* Q, ElemType e)
{
	LinkList s = (LinkList)malloc(sizeof(LNode));
	if (!s) /* 存储分配失败 */
		return ERROR;
	s->data = e;
	s->next = NULL;
	Q->rear->next = s;	/* 把拥有元素e的新结点s赋值给原队尾结点的后继 */
	Q->rear = s;		/* 把当前的s设置为队尾结点，rear指向s */
	return OK;
}

Status QueueDelete(LinkQueue* Q, ElemType* e)
{
	LinkList p;
	if (Q->front == Q->rear)
		return ERROR;
	p = Q->front->next;		/* 将欲删除的队头结点暂存给p */
	*e = p->data;				/* 将欲删除的队头结点的值赋值给e */
	Q->front->next = p->next;/* 将原队头结点的后继p->next赋值给头结点后继 */
	if (Q->rear == p)		/* 若队头就是队尾，则删除后将rear指向头结点 */
		Q->rear = Q->front;
	free(p);
	return OK;
}