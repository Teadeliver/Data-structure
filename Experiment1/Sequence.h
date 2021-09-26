#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define OK 11
#define ERROR -11
#define TRUE 1
#define FALSE 0
#define List_Init_Size 10         /* �洢�ռ��ʼ������ */
#define ListIncrement 10		/* ���Ա���ռ�ķ������� */

typedef int Elemtype;
typedef Elemtype ET;       /* ElemType����*/

typedef struct
{
	ET* data;			/* �洢����Ԫ�� */
	int length;				/* ʵ��Ԫ�ظ��� */
	int listsize;			/* ���Ա�ǰ���� */
}SqList;

typedef int Status;         /* ���״̬����*/

Status visit(ET c);

/* ������������ζ�L��ÿ������Ԫ����� */
Status ListTraverse(SqList L);

/* ����L������Ԫ�ظ��� */
int ListLength(SqList L);

/* ��ʼ��˳�����Ա� */
Status InitList(SqList* L);

Status FreeList(SqList* L);

/* �����������L�е�i��λ��֮ǰ�����µ�����Ԫ��e��L�ĳ��ȼ�1 */
Status ListInsert(SqList* L, int i, ET e);

/* ���������ɾ��L�ĵ�i������Ԫ�أ�����e������ֵ��L�ĳ��ȼ�1 */
Status ListDelete(SqList* L, int i, ET* e);

/* ����ĳԪ�ص�һ�γ��ֵ�λ�ã�������������Ԫ�ز����ڣ��򷵻�ֵΪ0 */
int LocateElem(SqList L, ET e);

/* �ϲ�La��Lb��Lc */
Status Merge(SqList* La, SqList* Lb, SqList* Lc);

/* ��e����L�е�i������Ԫ�ص�ֵ, i��ָλ�� */
Status GetElem(SqList L, int i, ET* e);

/*�����е������Ա�Lb�е�����La�е�����Ԫ�ز��뵽La��*/
void union_Sq(SqList* La, SqList Lb);