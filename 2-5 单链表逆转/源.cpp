#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType Data;
	PtrToNode   Next;
};
typedef PtrToNode List;

List Read(); /* ϸ���ڴ˲��� */
void Print(List L); /* ϸ���ڴ˲��� */

List Reverse(List L);

int main()
{
	List L1, L2;
	L1 = Read();
	L2 = Reverse(L1);
	Print(L1);
	Print(L2);
	return 0;
}

/* ��Ĵ��뽫��Ƕ������ */
List Reverse(List L) {
	List prev = NULL;
	List curr = L;
	List next;
	if (L == NULL || L->Next == NULL)
		return L;
	while (curr != NULL) {
		next = curr->Next;
		curr->Next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}