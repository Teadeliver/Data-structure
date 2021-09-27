#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表；空链表将输出NULL */

List Merge(List L1, List L2);

int main()
{
	List L1, L2, L;
	L1 = Read();
	L2 = Read();
	L = Merge(L1, L2);
	Print(L);
	Print(L1);
	Print(L2);
	return 0;
}

/* 你的代码将被嵌在这里 */
List Merge(List L1, List L2)
{
	List L;
	int num1 = 0, num2 = 0;
	while (L1)
	{
		num1 += 1;
		L1 = L1->Next;
	}
	while (L2)
	{
		num1 += 1;
		L2 = L2->Next;
	}
	if (num1 > num2)
	{
		L = L1;
		while (L2)
		{
			while (L)
			{
				if (L2->Data > L->Data)
				{
					L2->Next = L->Next;
					L->Next = L2;
					break;
				}
				L = L->Next;
			}
			L2 = L2->Next;
		}
	}
}