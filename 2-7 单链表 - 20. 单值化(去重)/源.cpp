#include "stdio.h"

typedef double LELEMENT;
typedef struct LNode
{
	LELEMENT data;
	struct LNode* next;
}LNODE;

typedef struct L
{
	int length;
	LNODE* head;
}LLIST;

int LElementEq(const LELEMENT* x, const LELEMENT* y);

void LListUnique(LLIST* list)
{
	/*
	˼·����ͨ��cur������������
	curÿ��һ���ڵ㣬
	����nextȥ����cur����Ľڵ㣬
	�鿴�Ƿ��нڵ�����ݺ�curָ��Ľڵ��������ͬ��
	�����ͬ����ͨ��preɾ�������ͬ���ݵĽڵ�
	ֱ��next������cur���ÿһ���ڵ㣬cur�Ż���������
	*/
	LNODE* cur = list->head->next;//curָ�����������ݵĵ�һ���ڵ�
	LNODE* pre = NULL;
	LNODE* next = NULL;
	while (NULL != cur) //cur��Ϊ�վ�ѭ��
	{
		pre = cur;//pre�������Ƿ���ɾ���ڵ㣬preָ��nextָ��Ľڵ��ǰһ��
		next = cur->next;//next������������������������
		while (NULL != next) {
			if (LElementEq(&cur->data, &next->data))//LElementEq������Ŀ�涨�������ж�ֵ�Ƿ���ȵĺ���
			{
				//���curָ��ڵ�����ݺ�nextָ��Ľڵ��������ͬ
				pre->next = next->next;/* preָ��nextָ��ڵ��ǰһ���ڵ㣬
									   �������д��������nextָ��Ľڵ��������ɾ�� */
				list->length--;//ɾ��һ���ڵ����������Ӧ��1
			}
			else
			{
				//���curָ��ڵ�����ݺ�nextָ��Ľڵ�����ݲ���ͬ
				pre = next;//�������൱��pre����ƶ�һ���ڵ�
			}
			next = next->next;//nextָ����һ���ڵ�
		}
		cur = cur->next;//curָ����һ���ڵ�
	}
}

int main()
{

}