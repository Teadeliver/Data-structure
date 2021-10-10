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

/* 你的代码将被嵌在这里 */
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
	if (S->Top1 + 1 == S->Top2)	/* 栈已满，不能再push新元素了 */
	{
		printf("Stack Full\n");
		return false;
	}
	if (Tag == 1)			/* 栈1有元素进栈 */
		S->Data[++S->Top1] = X; /* 若是栈1则先top1+1后给数组元素赋值。 */
	else if (Tag == 2)	/* 栈2有元素进栈 */
		S->Data[--S->Top2] = X; /* 若是栈2则先top2-1后给数组元素赋值。 */
	return true;
}
ElementType Pop(Stack S, int Tag) 
{
	if (Tag == 1)
	{
		if (S->Top1 == -1)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR; /* 说明栈1已经是空栈，溢出 */
		}
		return S->Data[S->Top1--]; /* 将栈1的栈顶元素出栈 */
	}
	else if (Tag == 2)
	{
		if (S->Top2 == S->MaxSize)
		{
			printf("Stack %d Empty\n", Tag);
			return ERROR; /* 说明栈2已经是空栈，溢出 */
		}
		return S->Data[S->Top2++]; /* 将栈2的栈顶元素出栈 */
	}
	return true;
}