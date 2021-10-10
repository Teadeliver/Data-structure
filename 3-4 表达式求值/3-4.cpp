#include "stdio.h"    
#include "stdlib.h" 
#include "string.h"

#include "math.h"  
#include "time.h"

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef char SElemType;

/* 顺序栈结构 */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack;

/*  构造一个空栈S */
Status InitStack(SqStack* S)
{
	/* S.data=(SElemType *)malloc(MAXSIZE*sizeof(SElemType)); */
	S->top = -1;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{
	return S.top + 1;
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
		return ERROR;
	*e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	S->top--;				/* 栈顶指针减一 */
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