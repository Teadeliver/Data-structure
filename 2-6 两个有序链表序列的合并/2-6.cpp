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
	L1 = L1->next; L2 = L2->next;
	List res = (List)malloc(sizeof(List));
	List tmp = res;
	while (L1 != NULL && L2 != NULL) {
		if ((L1->data) < (L2->data)) {
			tmp->next = L1;
		L1 = L1->next;
			tmp = tmp->next;
	}
		else {
			tmp->next = L2;
		L2 = L2->next;
			tmp = tmp->next;
	}
	}
	if (L1 != NULL) tmp->next = L1;
	if (L2 != NULL) tmp->next = L2;
	p1->next = NULL;
	p2->next = NULL;
	return res;
}
List Read() {
	int num;
	scanf("%d", &num);

	List L = (List)malloc(sizeof(Node));
	L->next = NULL;


	List tail;
	tail = L;
	for (int i = 0; i < num; ++i)
				{
		int data;
		scanf("%d", &data);
		List pNode = (List)malloc(sizeof(Node));
		pNode->data = data;
		tail->next = pNode;
		tail = pNode;
				}
	tail->next = NULL;
	return L;
			}

void Print(List L) {
	List pNode = L->next;
	if (pNode == NULL) {
		printf("NULL\n");
		return;
		}
	while (pNode != NULL) {
		printf("%d  ", pNode->data);
		pNode = pNode->next;
	}
	printf("\n");
}