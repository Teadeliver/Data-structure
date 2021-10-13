#include<stdio.h>
#include<stdlib.h>

#include<math.h>
#include<time.h>

#define STACK_INIT_SIZE 2000//初始分配量
#define ERROR 0
#define OK 1
typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base;//栈底指针
	SElemType* top;//栈顶指针
	int stacksize;//当前已分配的内存空间
}SqStack;

//初始化栈
Status InitStack(SqStack* s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//入栈
Status Push(SqStack* s, SElemType e)
{
	if ((s->top - s->base) >= s->stacksize)
		return ERROR;
	s->top++;
	*(s->top) = e;
	return OK;
}
//出栈
Status Pop(SqStack* s, SElemType* e)
{
	if (s->top == s->base)//栈为空
	{
		printf("invalid");
		return ERROR;
	}
	*e = *(s->top);
	s->top--;
	return OK;
}

int main()
{
	SqStack* s;
	int n, operation, e;
	SElemType p;
	s = (SqStack*)malloc(sizeof(SqStack));
	InitStack(s);
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &operation);
		switch (operation)
		{
		case 1:
		{
			scanf("%d", &p);
			Push(s, p);
			break;
		}
		case 0:
{
			if (Pop(s, &e))
	{
				printf("%d\n", e);
			}
			break;
		}
		}
	}
	return 0;
}