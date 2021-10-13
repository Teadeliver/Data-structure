#include<stdio.h>
#include<stdlib.h>

#include<math.h>
#include<time.h>

#define STACK_INIT_SIZE 2000//��ʼ������
#define ERROR 0
#define OK 1
typedef int Status;
typedef int SElemType;
typedef struct
{
	SElemType* base;//ջ��ָ��
	SElemType* top;//ջ��ָ��
	int stacksize;//��ǰ�ѷ�����ڴ�ռ�
}SqStack;

//��ʼ��ջ
Status InitStack(SqStack* s)
{
	s->base = (SElemType*)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}
//��ջ
Status Push(SqStack* s, SElemType e)
{
	if ((s->top - s->base) >= s->stacksize)
		return ERROR;
	s->top++;
	*(s->top) = e;
	return OK;
}
//��ջ
Status Pop(SqStack* s, SElemType* e)
{
	if (s->top == s->base)//ջΪ��
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