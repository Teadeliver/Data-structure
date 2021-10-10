#include <stdio.h>
#include <stdlib.h>

#define ERROR 1e8
typedef int ElementType;
typedef enum { push, pop, end } Operation;
typedef enum { false, true } bool;
typedef int Position;
struct SNode {
	ElementType* Data;
	Position Top1, Top2;
	int MaxSize;
};
typedef struct SNode* Stack;

Stack CreateStack(int MaxSize);
bool Push(Stack S, ElementType X, int Tag);
ElementType Pop(Stack S, int Tag);

Operation GetOp();  /* details omitted */
void PrintStack(Stack S, int Tag); /* details omitted */

int main()
{
	int N, Tag, X;
	Stack S;
	int done = 0;

	scanf("%d", &N);
	S = CreateStack(N);
	while (!done) {
		switch (GetOp()) {
		case push:
			scanf("%d %d", &Tag, &X);
			if (!Push(S, X, Tag)) printf("Stack %d is Full!\n", Tag);
			break;
		case pop:
			scanf("%d", &Tag);
			X = Pop(S, Tag);
			if (X == ERROR) printf("Stack %d is Empty!\n", Tag);
			break;
		case end:
			PrintStack(S, 1);
			PrintStack(S, 2);
			done = 1;
			break;
		}
	}
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
Stack CreateStack(int MaxSize)
{
	Stack newstack=(Stack)malloc(sizeof(struct SNode));
	newstack->Data = (ElementType*)malloc(sizeof(ElementType) * MaxSize);
	newstack->Top1 = -1;
	newstack->Top2 = MaxSize;
	newstack->MaxSize = MaxSize;
	return newstack;
}
bool Push(Stack S, ElementType X, int Tag)
{
	if (S->Top1 + 1 == S->Top2)	/* ջ������������push��Ԫ���� */
	{
		printf("Stack Full\n");
		return false;
	}
	if (Tag == 1)			/* ջ1��Ԫ�ؽ�ջ */
		S->Data[++S->Top1] = X; /* ����ջ1����top1+1�������Ԫ�ظ�ֵ�� */
	else if (Tag == 2)	/* ջ2��Ԫ�ؽ�ջ */
		S->Data[--S->Top2] = X; /* ����ջ2����top2-1�������Ԫ�ظ�ֵ�� */
	return true;
}
ElementType Pop(Stack S, int Tag) 
{
	if (Tag == 1)
	{
		if (S->Top1 == -1)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR; /* ˵��ջ1�Ѿ��ǿ�ջ����� */
		}
		return S->Data[S->Top1--]; /* ��ջ1��ջ��Ԫ�س�ջ */
	}
	else if (Tag == 2)
	{
		if (S->Top2 == S->MaxSize)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR; /* ˵��ջ2�Ѿ��ǿ�ջ����� */
		}
		return S->Data[S->Top2++]; /* ��ջ2��ջ��Ԫ�س�ջ */
	}
	return true;
}