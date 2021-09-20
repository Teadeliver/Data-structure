#include "operation.h"

Status visit(ET c)
{
	printf("%d ", c);
	return OK;
}

/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}

/* ����L������Ԫ�ظ��� */
int ListLength(SqList L)
{
	return L.length;
}

/* ��ʼ��˳�����Ա� */
Status InitList(SqList* L)
{
	L->data = (ET*)malloc(sizeof(ET) * List_Init_Size);
	if (!L->data)			/* �����ڴ�ʧ�� */
		exit(ERROR);
	L->length = 0;			/* �ձ���Ϊ0 */
	L->listsize = List_Init_Size;			/* ��ʼ���������� */
	return OK;
}

/* �������Ա� */
Status FreeList(SqList* L)
{
	free(L->data);
	L->data = NULL;
	L->length = 0;
	L->listsize = 0;
	return OK;
}

/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList* L, int i, ET e)
{
	int k;
	if (L->length == List_Init_Size)  /* ˳�����Ա��Ѿ��� */
		return ERROR;
	if (i<1 || i>L->length + 1)/* ��i�ȵ�һλ��С���߱����һλ�ú�һλ�û�Ҫ��ʱ */
		return ERROR;

	if (i <= L->length)        /* ����������λ�ò��ڱ�β */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* ��Ҫ����λ��֮�������Ԫ������ƶ�һλ */
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          /* ����Ԫ�ز��� */
	L->length++;

	return OK;
}

/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList* L, int i, ET* e)
{
	if (L->length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)                /* ���ɾ���������λ�� */
	{
		for (int k = i; k < L->length; k++)		/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

/* ����ĳԪ�ص�һ�γ��ֵ�λ�ã�������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ET e)
{
	int i;
	if (L.length == 0)
		return 0;
	for (i = 0; i < L.length; i++)
	{
		if (L.data[i] == e)
			return i + 1;		/* ����λ�� */
	}
	return 0;
}

/* �ϲ�La��Lb��Lc */
Status Merge(SqList* La, SqList* Lb, SqList* Lc)
{
	int i, j;
	Lc->data = (ET*)malloc(sizeof(int) * List_Init_Size * 2);
	assert(Lc->data);	/* ��������NULL������ */
	for (i = 0; i < La->length; i++, Lc->length++)
		Lc->data[i] = La->data[i];
	for (j = 0; j < Lb->length; i++, j++, Lc->length++)
		Lc->data[i] = Lb->data[j];
	return OK;
}

/* ��e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�� */
Status GetElem(SqList L, int i, ET* e)
{
	if (L.length == 0 || i<1 || i>L.length)
		return ERROR;
	*e = L.data[i - 1];

	return OK;
}

/*�����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
void union_Sq(SqList* La, SqList Lb)
{
	int La_len, Lb_len, i;
	ET e;                         /*������La��Lb��ͬ������Ԫ��e*/
	La_len = ListLength(*La);           /*�����Ա�ĳ��� */
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);              /*ȡLb�е�i������Ԫ�ظ���e*/
		if (!LocateElem(*La, e))         /*La�в����ں�e��ͬ����Ԫ��*/
			ListInsert(La, ++La_len, e); /*����*/
	}
}