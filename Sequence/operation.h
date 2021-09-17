#pragma once
#include <stdio.h>
#include "assert.h" 

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20          /* 存储空间初始分配量 */
typedef int ElemType;       /* ElemType类型*/
typedef struct
{
	ElemType data[MAXSIZE]; /* 存储数据元素 */
	int length;             /* 线性表当前长度 */
}SqList;

typedef int Status;         /* 标记状态类型*/

Status visit(ElemType c)
{
	printf("%d ", c);
	return OK;
}

/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
	int i;
	for (i = 0; i < L.length; i++)
		visit(L.data[i]);
	printf("\n");
	return OK;
}


/* 初始化顺序线性表 */
Status InitList(SqList* L)
{
	L->length = 0;
	return OK;
}

/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList* L, int i, ElemType e)
{
	int k;
	if (L->length == MAXSIZE)  /* 顺序线性表已经满 */
		return ERROR;
	if (i<1 || i>L->length + 1)/* 当i比第一位置小或者比最后一位置后一位置还要大时 */
		return ERROR;

	if (i <= L->length)        /* 若插入数据位置不在表尾 */
	{
		for (k = L->length - 1; k >= i - 1; k--)  /* 将要插入位置之后的数据元素向后移动一位 */
			L->data[k + 1] = L->data[k];
	}
	L->data[i - 1] = e;          /* 将新元素插入 */
	L->length++;

	return OK;
}

/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList* L, int i, ElemType* e)
{
	if (L->length == 0)               /* 线性表为空 */
		return ERROR;
	if (i<1 || i>L->length)         /* 删除位置不正确 */
		return ERROR;
	*e = L->data[i - 1];
	if (i < L->length)                /* 如果删除不是最后位置 */
	{
		for (int k = i; k < L->length; k++)/* 将删除位置后继元素前移 */
			L->data[k - 1] = L->data[k];
	}
	L->length--;
	return OK;
}