#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType data;
	PtrToNode   next;
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
	List prev = NULL;//ָ���Ѿ���ת������ĵ�һ���ڵ�
	List curr = L;//����ָ�룬ָ��ǰ��Ҫ��ת�Ľڵ�
	List next;//��ǰ��Ҫ��ת�Ľڵ����һ��
	if (L == NULL || L->next == NULL)
		return L;
	while (curr != NULL) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}