#include <stdio.h>    
#include "stdlib.h   

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20000 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef int SElemType;

/* ˳��ջ�ṹ */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
}SqStack;

/*  ����һ����ջS */
Status InitStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAXSIZE - 1) /* ջ�� */
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
	{
		printf("invalid\n");
		return ERROR;
	}
	*e = S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
	S->top--;				/* ջ��ָ���һ */
	return OK;
}

int main()
{
	int n, operation, e;
	SElemType flag;
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S);//��ʼ��ջ
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