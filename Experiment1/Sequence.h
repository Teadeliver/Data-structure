#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define OK 11
#define ERROR -11
#define TRUE 1
#define FALSE 0
#define List_Init_Size 10         /* 存储空间初始分配量 */
#define ListIncrement 10		/* 线性表储存空间的分配增量 */

typedef int Elemtype;
typedef Elemtype ET;       /* ElemType类型*/

typedef struct
{
	ET* data;			/* 存储数据元素 */
	int length;				/* 实际元素个数 */
	int listsize;			/* 线性表当前长度 */
}SqList;

typedef int Status;         /* 标记状态类型*/

Status visit(ET c);

/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L);

/* 返回L中数据元素个数 */
int ListLength(SqList L);

/* 初始化顺序线性表 */
Status InitList(SqList* L);

Status FreeList(SqList* L);

/* 操作结果：在L中第i个位置之前插入新的数据元素e，L的长度加1 */
Status ListInsert(SqList* L, int i, ET e);

/* 操作结果：删除L的第i个数据元素，并用e返回其值，L的长度减1 */
Status ListDelete(SqList* L, int i, ET* e);

/* 查找某元素第一次出现的位置，若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L, ET e);

/* 合并La与Lb到Lc */
Status Merge(SqList* La, SqList* Lb, SqList* Lc);

/* 用e返回L中第i个数据元素的值, i是指位置 */
Status GetElem(SqList L, int i, ET* e);

/*将所有的在线性表Lb中但不在La中的数据元素插入到La中*/
void union_Sq(SqList* La, SqList Lb);