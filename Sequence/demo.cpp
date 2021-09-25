#include "Sequence.h"
void TestSequence()
{
	SqList La, Lb, Lc;//��ʼ��˳���
	int flag = InitList(&La);
	assert(flag);
	printf("˳���La��ʼ��Ϊ�ձ��䳤��Ϊ%d\n", La.length);
	FreeList(&La);
	InitList(&La);
	for (int i = 1; i <= 5; i++)//˳���ͷ�����β���1~5
	{
		ListInsert(&La, 1, i);
	}
	printf("˳���ͷ�����β���1-5��˳���La����Ϊ%d\n", La.length);
	flag = ListTraverse(La);
	assert(flag);

	flag = ListInsert(&La, La.length + 1, 99);
	assert(flag);
	printf("˳���β������99��˳���La����Ϊ%d\n", La.length);
	flag = ListTraverse(La);
	assert(flag);

	int temp = ListDelete(&La, 2, &temp);
	printf("ɾ���ڶ���Ԫ��%d��˳���La����Ϊ%d\n", temp, La.length);
	flag = ListTraverse(La);
	assert(flag);

	int location = LocateElem(La, 99);
	printf("����Ѱ��99��λ��\n");
	if (location != 0)
	{
		printf("����˳����һ�γ��ֵ�λ����%d\n", location);
	}
	else
	{
		printf("����˳���û���ҵ�\n");
	}

	InitList(&La);
	printf("��La˳����ÿ�\n\n");

	InitList(&La);
	InitList(&Lb);
	InitList(&Lc);
	for (int i = 5; i >= 1; i--)//˳���ͷ�����β���5-1
	{
		ListInsert(&La, 1, i);
	}
	for (int i = 10; i >= 4; i--)//˳���ͷ�����β���10-4
	{
		ListInsert(&Lb, 1, i);
	}
	printf("La˳���ͷ�����β���5-1��˳���La����Ϊ%d\n", La.length);
	ListTraverse(La);
	printf("Lb˳���ͷ�����β���10-4��˳���Lb����Ϊ%d\n", Lb.length);
	ListTraverse(Lb);
	printf("���Թ鲢La��LbΪLc�����dΪ��\n");
	Merge(&La, &Lb, &Lc);
	ListTraverse(Lc);

	union_Sq(&La, Lb);
	printf("����La = La��Lb�����Ϊ��\n");
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

