#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode* PtrToLNode;
struct LNode {
	ElementType Data;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find(List L, ElementType X);
List Insert(List L, ElementType X, Position P);
List Delete(List L, Position P);

int main()
{
	List L;
	ElementType X;
	Position P, tmp;
	int N;

	L = NULL;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		L = Insert(L, X, L);
		if (L == ERROR) printf("Wrong Answer\n");
	}
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &X);
		P = Find(L, X);
		if (P == ERROR)
			printf("Finding Error: %d is not in.\n", X);
		else {
			L = Delete(L, P);
			printf("%d is found and deleted.\n", X);
			if (L == ERROR)
				printf("Wrong Answer or Empty List.\n");
		}
	}
	L = Insert(L, X, NULL);
	if (L == ERROR) printf("Wrong Answer\n");
	else
		printf("%d is inserted as the last element.\n", X);
	P = (Position)malloc(sizeof(struct LNode));
	tmp = Insert(L, X, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	tmp = Delete(L, P);
	if (tmp != ERROR) printf("Wrong Answer\n");
	for (P = L; P; P = P->Next) printf("%d ", P->Data);
	return 0;
}

/* 你的代码将被嵌在这里 */
Position Find(List L, ElementType X)
{
	if (!L)
		return ERROR;
	while (L)
	{
		if (L->Data == X)
			return L;
		L = L->Next;
	}
	return ERROR;
}
List Insert(List L, ElementType X, Position P)
{
	List q, Pre = L;
	if (Pre == P)
	{
		q = (List)malloc(sizeof(struct LNode));
		q->Data = X;
		q->Next = P;
		return q;
	}
	while (Pre->Next && Pre->Next != P)
	{
		Pre = Pre->Next;
	}
	if (Pre->Next != P)
	{
		printf("Wrong Position for Insertion\n");
		return ERROR;
	}
	q = (List)malloc(sizeof(struct LNode));
	q->Data = X;
	q->Next = P;
	Pre->Next = q;
	return L;
}

List Delete(List L, Position P)
{
	List Pre = L;
	if (L->Next == NULL)
	{
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
	if (Pre == P)
	{
		return L->Next;
	}
	while (Pre->Next && Pre->Next != P)
	{
		Pre = Pre->Next;
	}
	if (Pre->Next != P)
	{
		printf("Wrong Position for Deletion\n");
		return ERROR;
	}
	Pre->Next = P->Next;
	return L;
}
//Position Find(List L, ElementType X)
//{
//	List head = L;
//	while (head)
//	{
//		if (head->Data == X)
//			return head;
//		head = head->Next;
//	}
//	return ERROR;
//}
//List Insert(List L, ElementType X, Position P)
//{
//	List head = L, temp;
//	if (head == P)
//	{
//		temp = (List)malloc(sizeof(struct LNode));
//		temp->Data = X;
//		temp->Next = P;
//		return temp;
//	}
//	while (head)
//	{
//		if (head->Next == P)
//		{
//			temp = (List)malloc(sizeof(struct LNode));
//			if (temp)
//			{
//				temp->Next = P;
//			}
//			head->Next = temp;
//			temp->Data = X;
//			return L;
//		}
//		head = head->Next;
//	}
//	printf("Wrong Position for Insertion\n");
//	return ERROR;
//}
//List Delete(List L, Position P)
//{
//	List head = L;
//	if (head == P)
//	{
//		head = head->Next;
//		return head;
//	}
//	while (head)
//	{
//		if (head->Next == P)
//		{
//			head->Next = head->Next->Next;
//			return L;
//		}
//		head = head->Next;
//	}
//	printf("Wrong Position for Deletion\n");
//	return ERROR;
//}