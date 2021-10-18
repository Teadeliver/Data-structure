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
Status InitStack(SqStack* S, int MAXSIZE)
{

	S->data = (SElemType*)malloc(MAXSIZE * sizeof(SElemType));
	S->top = -1;
	S->MAXSIZE = MAXSIZE;
	return OK;
}

/* ��ջ���գ�����S��ջ��Ԫ��; ���򷵻�ERROR */
SElemType GetTop(SqStack S)
{
	if (S.top == -1)	/* ջ��*/
		return ERROR;
	else
		return S.data[S.top];
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == S->MAXSIZE - 1)	/* ջ�� */
	{
		return ERROR;
	}
	S->top++;				/* ջ��ָ������һ */
	S->data[S->top] = e;    /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
	return OK;
}


Status Caculate(int N, int M, SElemType num[])
{
	/*flag��ʾ������ɫ��ans��ʶ��ƥ����ɫ*/
	int flag = 0, ans = 1;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S, M);
	while (flag < N)
	{
		if (GetTop(*S) != ans)	/* ���ܶ��ϵ���ɫ��ƥ�� */
		{
			if (num[flag] != ans) /* ��������Ļ����Բ�ƥ�� */
			{
				if (!Push(S, num[flag])) /* �ѻ���ӵ������� */
				{
					return ERROR;	/* ��������ʧ��*/
				}
			}
			else/* ��������Ļ���ƥ�� */
				ans++;	/* ��һ����Ҫƥ����ɫ */
			flag++;	/* ׼��ƥ����һ������ */
		}
		else/* ������ܶ��ϵ���ɫƥ�� */
		{
			ans++;	/* ��һ����Ҫƥ����ɫ */
			S->top--;	/* ��һ����Ҫƥ����ɫ */
		}
	}
	while (S->top != -1)	/* ���л��ﶼ������ֱ���жϻ��ܵĻ��� */
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