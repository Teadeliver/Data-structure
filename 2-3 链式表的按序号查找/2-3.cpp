#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

ElementType FindKth(List L, int K);

int main()
{
	int N, K;
	ElementType X;
	List L = Read();
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &K);
		X = FindKth(L, K);
		if (X != ERROR)
			printf("%d ", X);
		else
			printf("NA ");
	}
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
ElementType FindKth(List L, int K)
{
	int i = 1;
	while (L && i < K)
	{
		L = L->Next;
		i++;
	}
	if (!L || i > K)
	{
		return ERROR;
	}
	return L->Data;
}