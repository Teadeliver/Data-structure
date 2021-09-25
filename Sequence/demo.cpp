#include "Sequence.h"
void TestSequence()
{
	SqList La, Lb, Lc;//初始化顺序表
	int flag = InitList(&La);
	assert(flag);
	printf("顺序表La初始化为空表，其长度为%d\n", La.length);
	FreeList(&La);
	InitList(&La);
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

	int location = LocateElem(La, 99);
	printf("尝试寻找99的位置\n");
	if (location != 0)
	{
		printf("其在顺序表第一次出现的位置是%d\n", location);
	}
	else
	{
		printf("其在顺序表没有找到\n");
	}

	InitList(&La);
	printf("将La顺序表置空\n\n");

	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	for (int i = 5; i >= 1; i--)//顺序表头部依次插入5-1
	{
		ListInsert(&La, 1, i);
	}
	for (int i = 10; i >= 4; i--)//顺序表头部依次插入10-4
	{
		ListInsert(&Lb, 1, i);
	}
	printf("La顺序表头部依次插入5-1，顺序表La长度为%d\n", La.length);
	ListTraverse(La);
	printf("Lb顺序表头部依次插入10-4，顺序表Lb长度为%d\n", Lb.length);
	ListTraverse(Lb);
	printf("尝试归并La与Lb为Lc，结果d为：\n");
	Merge(&La, &Lb, &Lc);
	ListTraverse(Lc);

	union_Sq(&La, Lb);
	printf("尝试La = La∪Lb，结果为：\n");
	ListTraverse(La);
}

void TestLinked()
{

}
int main()
{
	TestSequence();
	TestLinked();
}

