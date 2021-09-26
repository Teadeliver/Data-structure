#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define  True 11
#define  False 0
#define  Ok 111
#define  Error -111
#define  List_Init_Size 10
#define  ListIncrement 10

typedef int  Status;//状态类型
typedef ElemType ET;

typedef struct {
	int num;         //专家号，不重复，可用于查找专家
	char name[30];   //专家姓名，可能重复
}ElemType;			//元素类型-----专家信息数据类型

typedef  struct Lnode {
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;  //链表结点类型定义

Status InitList_L();