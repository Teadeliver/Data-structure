void LListUnique(LLIST* list)
{
	LNODE* cur = list->head->next;
	LNODE* pre = NULL;
	LNODE* next = NULL;
	while (NULL != cur) {
		pre = cur;
		next = cur->next;
		while (NULL != next) {
			if (LElementEq(&cur->data, &next->data))
			{
				pre->next = next->next;
				list->length--;
			}
			else
			{
				pre = next;
			}
			next = next->next;
		}
		cur = cur->next;
	}
}