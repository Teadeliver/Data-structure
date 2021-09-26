#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int data;
	struct ListNode* next;
};

struct ListNode* createlist();

int main()
{
	struct ListNode* p, * head = NULL;

	head = createlist();
	for (p = head; p != NULL; p = p->next)
		printf("%d ", p->data);
	printf("\n");

	return 0;
}

/* 你的代码将被嵌在这里 */
struct ListNode* createlist()
{
	int num;
	struct ListNode* head;
	struct ListNode* temp;
	temp = (struct ListNode*)malloc(sizeof(struct ListNode));
	scanf("%d", &num);
	if (num != -1)
	{
		head = temp;
		temp->data = num;
		temp->next = NULL;
	}
	scanf("%d", &num);
	while (num != -1)
	{
		temp = (struct ListNode*)malloc(sizeof(struct ListNode));
		temp->data = num;
		temp->next = head;
		head = temp;
		scanf("%d", &num);
	}
	return head;
}