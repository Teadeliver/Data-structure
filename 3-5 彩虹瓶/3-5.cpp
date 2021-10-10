#include "stdio.h"    
#include "stdlib.h"   

#define OK 1
#define ERROR 0

typedef int Status;
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */

/* 顺序栈结构 */
typedef struct
{
	SElemType* data;
	int top; /* 用于栈顶指针 */
	int MAXSIZE;
}SqStack;

/*  构造一个空栈S */
Status InitStack(SqStack* S,int MAXSIZE)
{
	S->data = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	S->top = -1;
	S->MAXSIZE = MAXSIZE;
	return OK;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S, SElemType* e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == S->MAXSIZE - 1) /* 栈满 */
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
		return ERROR;
	*e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	S->top--;				/* 栈顶指针减一 */
	return OK;
}

Status Caculate(int N, int M, SElemType num[])
{
	int flag = 0;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S, M);
	for (int i = 1; i < N; i++)
	{
		int x = 0;
		while (i != num[flag])
		{
			if (!Push(S, num[flag++]))
				return ERROR;
		}
		while (i == num[flag])
		{
			i++;
			flag++;
			SElemType temp;
			while (1)
			{
				if (GetTop(*S, &temp) && i == temp)
				{
					i++;
					Pop(S, &temp);
				}
			}
		}
	}
	return OK;
}

int main()
{
	int N, M, K;
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < K; i++)
	{
		SElemType* num = (SElemType*)malloc(sizeof(int) * N);
		for (int j = 0; j < N; j++)
		{
			scanf("%d", num + j);
		}
		if (Caculate(N, M, num))
		{
			printf("YES\n");
			continue;
		}
		else
		{
			printf("NO\n");
			continue;
		}
	}
}

