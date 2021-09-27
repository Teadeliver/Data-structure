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
List Merge(List L1, List L2) {
	List p1 = L1, p2 = L2;
	L1 = L1->Next; L2 = L2->Next;
	List res = (List)malloc(sizeof(List));
	List tmp = res;
	while (L1 != NULL && L2 != NULL) {
		if ((L1->Data) < (L2->Data)) {
			tmp->Next = L1;
		L1 = L1->Next;
			tmp = tmp->Next;
	}
		else {
			tmp->Next = L2;
		L2 = L2->Next;
			tmp = tmp->Next;
	}
	}
	if (L1 != NULL) tmp->Next = L1;
	if (L2 != NULL) tmp->Next = L2;
	p1->Next = NULL;
	p2->Next = NULL;
	return res;
}
List Read() {
	int num;
	scanf("%d", &num);

	List L = (List)malloc(sizeof(Node));
	L->Next = NULL;


	List tail;
	tail = L;
	for (int i = 0; i < num; ++i)
				{
		int data;
		scanf("%d", &data);
		List pNode = (List)malloc(sizeof(Node));
		pNode->Data = data;
		tail->Next = pNode;
		tail = pNode;
				}
	tail->Next = NULL;
	return L;
			}

void Print(List L) {
	List pNode = L->Next;
	if (pNode == NULL) {
		printf("NULL\n");
		return;
		}
	while (pNode != NULL) {
		printf("%d  ", pNode->Data);
		pNode = pNode->Next;
	}
	printf("\n");
}