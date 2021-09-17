#include "operation.h"

int main()
{
	SqList La;//初始化顺序表
	int flag = InitList(&La);
	assert(flag);
	printf("顺序表La初始化为空表，其长度为%d\n", La.length);

	for (int i = 1; i <= 5; i++)//顺序表头部依次插入1~5
	{
		ListInsert(&La, 1, i);
	}
	printf("顺序表头部依次插入1-5，顺序表La长度为%d\n", La.length);
	flag = ListTraverse(La);
	assert(flag);

	flag = ListInsert(&La, La.length + 1, 99);
	assert(flag);
	printf("顺序表尾部插入99，顺序表La长度为%d\n", La.length);
	flag = ListTraverse(La);
	assert(flag);

	int temp = ListDelete(&La, 2, &temp);
	printf("删除第二个元素%d，顺序表La长度为%d\n", temp, La.length);
	flag = ListTraverse(La);
	assert(flag);

}