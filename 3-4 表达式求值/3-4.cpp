#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;
typedef char SElemType;

/* 顺序栈结构 */
typedef struct
{
	SElemType data[MAXSIZE];
	int top; /* 用于栈顶指针 */
}SqStack;

/*  构造一个空栈S */
Status InitStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* 把S置为空栈 */
Status ClearStack(SqStack* S)
{
	S->top = -1;
	return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(SqStack S)
{
	if (S.top == -1)
		return TRUE;
	else
		return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(SqStack S)
{
	return S.top + 1;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(SqStack S, SElemType* e)
{
	if (S.top == -1)
		return ERROR;
	else
		*e = S.data[S.top];
	return OK;
}

/* 插入元素e为新的栈顶元素 */
Status Push(SqStack* S, SElemType e)
{
	if (S->top == MAXSIZE - 1) /* 栈满 */
	{
		return ERROR;
	}
	S->top++;				/* 栈顶指针增加一 */
	S->data[S->top] = e;  /* 将新插入元素赋值给栈顶空间 */
	return OK;
}

/* 若栈不空，则删除S的栈顶元素，用e返回其值，并返回OK；否则返回ERROR */
Status Pop(SqStack* S, SElemType* e)
{
	if (S->top == -1)
		return ERROR;
	*e = S->data[S->top];	/* 将要删除的栈顶元素赋值给e */
	S->top--;				/* 栈顶指针减一 */
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
	//	if (input[i] >= '0' && input[i] <= '9')//字符如果是数字
	//	{
	//		output[flag++] = input[i++];
	//		continue;
	//	}
	//	else//字符如果是运算符
	//	{
	//		if (get_level(input[i]) == 1)//遇见左括号直接入栈
	//		{
	//			Push(tran_stack, input[i++]);
	//			continue;
	//		}
	//		if (get_level(input[i]) == 4)//遇见右括号
	//		{
	//			Push(tran_stack, input[i++]);
	//			continue;
	//		}
	//		if (get_level(input[i]) == 3)//遇到乘号和除号直接入栈
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
		{/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
			printf("%c", str[i++]);
			if (!isdigit(str[i]))
			{
				printf(" ");
			}
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和又括号匹配时弹出，这个后面单独讨论。弹出后将优先级低的运算符压入栈中*/
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
		/*当遇到右括号是，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if (str[i] == ')')
		{
			PopStack(S, &e);
			while (e != '(')
			{
				printf("%c ", e);
				PopStack(S, &e);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
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
			printf("\n输入格式错误！\n");
			return;
		}
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
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