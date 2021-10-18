#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* �洢�ռ��ʼ������ */

typedef int Status;
typedef char SElemType;

/* ˳��ջ�ṹ */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* ����ջ��ָ�� */
}SqStack;

/*  ����һ����ջS */
Status InitStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* ��S��Ϊ��ջ */
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* ��ջSΪ��ջ���򷵻�TRUE�����򷵻�FALSE */
Status StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

/* ����S��Ԫ�ظ�������ջ�ĳ��� */
int StackLength(SqStack S)
{
	return S.top + 1;
}

/* ��ջ���գ�����e����S��ջ��Ԫ�أ�������OK�����򷵻�ERROR */
Status GetTop(SqStack S, SElemType* e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/* ����Ԫ��eΪ�µ�ջ��Ԫ�� */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAXSIZE - 1) /* ջ�� */
	{
		return ERROR;
	}
	S->top++;				/* ջ��ָ������һ */
	S->data[S->top] = e;  /* ���²���Ԫ�ظ�ֵ��ջ���ռ� */
	return OK;
}

/* ��ջ���գ���ɾ��S��ջ��Ԫ�أ���e������ֵ��������OK�����򷵻�ERROR */
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/* ��Ҫɾ����ջ��Ԫ�ظ�ֵ��e */
	S->top--;				/* ջ��ָ���һ */
	return OK;
}

Status get_level(char ch)
{
	if (ch == '(')
		return 1;
	else
		if (ch == '+' || ch == '-')
			return 2;
		else
			if (ch == '*' || ch == '/')
				return 3;
			else
				return 4;
}

char* Transform(char* str)
{
	//SqStack* tran_stack = (SqStack*)malloc(sizeof(SqStack));
	//InitStack(tran_stack);
	//char output[MAXSIZE];
	//int i = 0, flag = 0;
	//while (i < strlen(input))
	//{
	//	if (input[i] >= '0' && input[i] <= '9')//�ַ����������
	//	{
	//		output[flag++] = input[i++];
	//		continue;
	//	}
	//	else//�ַ�����������
	//	{
	//		if (get_level(input[i]) == 1)//����������ֱ����ջ
	//		{
	//			Push(tran_stack, input[i++]);
	//			continue;
	//		}
	//		if (get_level(input[i]) == 4)//����������
	//		{
	//			Push(tran_stack, input[i++]);
	//			continue;
	//		}
	//		if (get_level(input[i]) == 3)//�����˺źͳ���ֱ����ջ
	//		{
	//			Push(tran_stack, input[i++]);
	//			continue;
	//		}
	//	}
	//}
	//return output;
	int i = 0;
	SElemType e;
	SqStack* tran_stack = (SqStack*)malloc(sizeof(SqStack));
	InitStack(tran_stack);
	while (str[i] != '\0')
	{
		while (isdigit(str[i]))
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ���������������Ŵ���ѹջ����Ϊ��
		����Ҫ��������ƥ��ʱ������������浥�����ۡ����������ȼ��͵������ѹ��ջ��*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (!StackLength(S))
			{
				PushStack(S, str[i]);
			}
			else
			{
				do
				{
					PopStack(S, &e);
					if (e == '(')
					{
						PushStack(S, e);
					}
					else
					{
						printf("%c ", e);
					}
				} while (StackLength(S) && e != '(');

				PushStack(S, str[i]);
			}
		}
		/*�������������ǣ���������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
		������ֻ��������ӡ��������Ҳ��ѹջ��*/
		else if (str[i] == ')')
		{
			PopStack(S, &e);
			while (e != '(')
			{
				printf("%c ", e);
				PopStack(S, &e);
			}
		}
		/*�ˡ����������Ŷ������ȼ��ߵģ�ֱ��ѹջ*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
		{
			PushStack(S, str[i]);
		}

		else if (str[i] == '\0')
		{
			break;
		}

		else
		{
			printf("\n�����ʽ����\n");
			return;
		}
		i++;
	}
	/*����ջ��ʣ�����������ε�ջ��ӡ*/
	while (StackLength(S))
	{
		PopStack(S, &e);
		printf("%c ", e);
	}
}

int main()
{
	char input[MAXSIZE];
	char* output;
	gets_s(input);
	output = Transform(input);
	printf("%s", output);
}