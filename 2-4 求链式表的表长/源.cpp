#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode List;

List Read(); /* ϸ���ڴ˲��� */

int Length(List L);

int main()
{
	List L = Read();
	printf("%d\n", Length(L));
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
int Length(List L)
{
	int num = 0;
	while (L)
	{
		num += 1;
		L = L->Next;
	}
	return num;
}