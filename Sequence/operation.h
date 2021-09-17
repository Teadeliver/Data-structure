#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h> 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* �洢�ռ��ʼ������ */
typedef int ElemType;       /* ElemType����*/
typedef struct
{
	ElemType* data;			/* �洢����Ԫ�� */
	int length;             /* ���Ա�ǰ���� */
}SqList;

typedef int Status;         /* ���״̬����*/

Status visit(ElemType c)
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
	L->data = (ElemType*)malloc(sizeof(int) * MAXSIZE);
	L->length = 0;
	return OK;
}

/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList* L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)  /* ˳�����Ա��Ѿ��� */
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
Status ListDelete(SqList* L, int i, ElemType* e)
{
	if (L->length == 0)               /* ���Ա�Ϊ�� */
		return ERROR;
	if (i<1 || i>L->length)         /* ɾ��λ�ò���ȷ */
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)                /* ���ɾ���������λ�� */
	{
		for (int k = i; k < L->length; k++)/* ��ɾ��λ�ú��Ԫ��ǰ�� */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}

/* ����ĳԪ�ص�һ�γ��ֵ�λ�ã�������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ElemType e)
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
	Lc->data = (ElemType*)malloc(sizeof(int) * MAXSIZE * 2);
	assert(Lc->data);	/* ��������NULL������ */
	for (i = 0; i < La->length; i++, Lc->length++)
		Lc->data[i] = La->data[i];
	for (j = 0; j < Lb->length; i++, j++, Lc->length++)
		Lc->data[i] = Lb->data[j];
	return OK;
}

/* ��e����L�е�i������Ԫ�ص�ֵ,ע��i��ָλ�� */
Status GetElem(SqList L, int i, ElemType* e)
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
	ElemType e;                         /*������La��Lb��ͬ������Ԫ��e*/
	La_len = ListLength(*La);           /*�����Ա�ĳ��� */
	Lb_len = ListLength(Lb);
	for (i = 1; i <= Lb_len; i++)
	{
		GetElem(Lb, i, &e);              /*ȡLb�е�i������Ԫ�ظ���e*/
		if (!LocateElem(*La, e))         /*La�в����ں�e��ͬ����Ԫ��*/
			ListInsert(La, ++La_len, e); /*����*/
	}
}