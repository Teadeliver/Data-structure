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

typedef int  Status;//״̬����
typedef ElemType ET;

typedef struct {
	int num;         //ר�Һţ����ظ��������ڲ���ר��
	char name[30];   //ר�������������ظ�
}ElemType;			//Ԫ������-----ר����Ϣ��������

typedef  struct Lnode {
	ElemType data;
	struct Lnode* next;
}LNode, * LinkList;  //���������Ͷ���

Status InitList_L();