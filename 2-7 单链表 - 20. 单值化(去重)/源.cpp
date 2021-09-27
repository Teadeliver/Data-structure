#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct Node* PtrToNode;
struct Node {
	ElementType data;
	PtrToNode   next;
};
typedef struct Node LLIST;

void LListUnique(LLIST* list);

int main()
{

}
void LListUnique(LLIST* list)
{
	LLIST* head = list, * save = list;
	LLIST temp;
	while (list)
	{
		temp.data = list->data; 
		while (head->next)
		{
			if (head->next->data == temp.data)
			{
				head->next = head->next->next;
			}
			head = head->next;
		}
		list = list->next;
	}
	printf("结构体大小为 %d", sizeof(LLIST));
	printf("%f", *(double*)(list + sizeof(LLIST*)));
}