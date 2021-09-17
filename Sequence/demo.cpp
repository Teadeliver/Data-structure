#include "operation.h"

int main()
{
	SqList La;//��ʼ��˳���
	int flag = InitList(&La);
	assert(flag);
	printf("˳���La��ʼ��Ϊ�ձ��䳤��Ϊ%d\n", La.length);

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

}