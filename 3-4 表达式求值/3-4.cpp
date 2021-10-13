#include "stdio.h"    
#include "stdlib.h" 
#include "string.h"

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef char SElemType;

/* ˳��ջ�ṹ */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
}SqStack;

/*  ����һ����ջS */
Status InitStack(SqStack* S)
{
	/* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
	S->top = -1;
	return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqStack S)
{
	return S.top + 1;
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
		return ERROR;
	*e = S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
	S->top--;				/* ջ��ָ���һ */
	return OK;
}

void transformation(char input[], char output[], SqStack* S)
{
	int flag = 0;
	for (int i = 0; i < strlen(input); i++)
	{
		if (input[i] >= '0' && input[i] <= '9')
		{
			output[flag++] = input[i];
		}
		else
		{
			if (input[i] == '(')
			{
				Push(S, input[i]);
			}
			else
			{
				if ()
			}
		}
	}
}

int main()
{
	char input[20], output[20];
	SqStack* S = (SqStack*)malloc(sizeof(SqStack));
	InitStack(S);
	scanf("%s", input);
	transformation(input, output, S);
}