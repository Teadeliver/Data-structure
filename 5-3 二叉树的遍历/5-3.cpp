#include <stdio.h>
#include <stdlib.h>

typedef char ElementType;
typedef struct TNode* Position;
typedef Position BinTree;
struct TNode {
	ElementType Data;
	BinTree Left;
	BinTree Right;
};

BinTree CreatBinTree(); /* 实现细节忽略 */
void InorderTraversal(BinTree BT);
void PreorderTraversal(BinTree BT);
void PostorderTraversal(BinTree BT);
void LevelorderTraversal(BinTree BT);

int main()
{
	BinTree BT = CreatBinTree();
	printf("Inorder:");    InorderTraversal(BT);    printf("\n");
	printf("Preorder:");   PreorderTraversal(BT);   printf("\n");
	printf("Postorder:");  PostorderTraversal(BT);  printf("\n");
	printf("Levelorder:"); LevelorderTraversal(BT); printf("\n");
	return 0;
}
/* 你的代码将被嵌在这里 */
void InorderTraversal(BinTree BT)
{
	if (BT)
	{
		InorderTraversal(BT->Left);
		printf(" %c", BT->Data);
		InorderTraversal(BT->Right);
	}
}
void PreorderTraversal(BinTree BT)
{
	if (BT)
	{
		printf(" %c", BT->Data);
		PreorderTraversal(BT->Left);
		PreorderTraversal(BT->Right);
	}
}
void PostorderTraversal(BinTree BT)
{
	if (BT)
	{
		PostorderTraversal(BT->Left);
		PostorderTraversal(BT->Right);
		printf(" %c", BT->Data);
	}
}
void LevelorderTraversal(BinTree BT)
{
	BinTree p;
	BinTree q[50];

	int head = 0; int tail = 0;
	if (BT)
	{
		q[tail++] = BT;
		while (head != tail)
		{
			p = q[head++];
			printf(" %c", p->Data);
			if (p->Left != NULL)
			{
				q[tail++] = p->Left;
			}
			if (p->Right != NULL)
			{
				q[tail++] = p->Right;
			}
		}
	}
}