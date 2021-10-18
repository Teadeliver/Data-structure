#include <stdio.h>    
#include "stdlib.h   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20000 /* 存储空间初始分配量 */

typedef int Status;
typedef int SElemType;

/* 顺序栈结构 */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack;

/*  构造一个空栈S */
Status InitStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAXSIZE - 1) /* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;  /* 将新插入元素赋值给栈顶空间 */
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1)
	{
		printf("invalid\n");
		return ERROR;
	}
	*e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	S->top--;				/* 栈顶指针减一 */
	return OK;
}

int main()
{
	int n, operation, e;
	SElemType flag;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S);//初始化栈
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &operation);
		switch (operation)
		{
		case 1:
		{
			scanf("%d", &flag);
			Push(S, flag);
			break;
		}
		case 0:
		{
			if (Pop(S, &e))
			{
				printf("%d\n", e);
			}
			break;
		}
		}
	}
}