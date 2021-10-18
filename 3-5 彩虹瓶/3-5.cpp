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
Status InitStack(SqStack* S, int MAXSIZE)
{

	S->data = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	S->top = -1;
	S->MAXSIZE = MAXSIZE;
	return OK;
}

/* 若栈不空，返回S的栈顶元素; 否则返回ERROR */
SElemType GetTop(SqStack S)
{
	if (S.top == -1)	/* 栈空*/
		return ERROR;
	else
		return S.data[S.top];
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == S->MAXSIZE - 1)	/* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;    /* 将新插入元素赋值给栈顶空间 */
	return OK;
}


Status Caculate(int N, int M, SElemType num[])
{
	/*flag表示发货颜色，ans标识需匹配颜色*/
	int flag = 0, ans = 1;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S, M);
	while (flag < N)
	{
		if (GetTop(*S) != ans)	/* 货架顶上的颜色不匹配 */
		{
			if (num[flag] != ans) /* 如果搬来的货物仍不匹配 */
			{
				if (!Push(S, num[flag])) /* 把货物加到架子上 */
				{
					return ERROR;	/* 货架满，失败*/
				}
			}
			else/* 如果搬来的货物匹配 */
				ans++;	/* 下一个需要匹配颜色 */
			flag++;	/* 准备匹配下一个货物 */
		}
		else/* 如果货架顶上的颜色匹配 */
		{
			ans++;	/* 下一个需要匹配颜色 */
			S->top--;	/* 下一个需要匹配颜色 */
		}
	}
	while (S->top != -1)	/* 所有货物都发货后，直接判断货架的货物 */
	{
		if (ans == GetTop(*S))
		{
			ans++;
			S->top--;
		}
		else
		{
			return ERROR;
		}
	}
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