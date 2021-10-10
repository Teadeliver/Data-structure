#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType data;
	PtrToNode   next;
};
typedef PtrToNode List;

List Read(); /* 细节在此不表 */
void Print(List L); /* 细节在此不表 */

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

/* 你的代码将被嵌在这里 */
List Reverse(List L) {
	List prev = NULL;//指向已经逆转的链表的第一个节点
	List curr = L;//工作指针，指向当前需要逆转的节点
	List next;//当前需要逆转的节点的下一个
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