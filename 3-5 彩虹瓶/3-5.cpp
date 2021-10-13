#include "stdio.h"    
#include "stdlib.h"   

#define OK 1
#define ERROR 0

typedef int Status;
typedef int SElemType; /* SElemType���͸���ʵ������������������Ϊint */

/* ˳��ջ�ṹ */
typedef struct
{
	SElemType* data;
	int top; /* ����ջ��ָ�� */
	int MAXSIZE;
}SqStack;

/*  ����һ����ջS */
Status InitStack(SqStack* S,int MAXSIZE)
{
	S->data = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	S->top = -1;
	S->MAXSIZE = MAXSIZE;
	return OK;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(SqStack S, SElemType* e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == S->MAXSIZE - 1) /* ջ�� */
	{
		return ERROR;
	}
	S->top++;				/* ջ��ָ������һ */
	S->data[S->top] = e;  /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
	S->top--;				/* ջ��ָ���һ */
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

