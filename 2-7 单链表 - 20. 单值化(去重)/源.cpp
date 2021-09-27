#include <stdio.h>

int main()
{
	LLIST a;
	LListCreate(&a);
	LListInput(&a);
	LListUnique(&a);
	LListOutput(&a);
	putchar('\n');
	LListDestroy(&a);
	return 0;
}