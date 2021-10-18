#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<assert.h>

#define INITSIZE 20
#define INCREMENT 10
#define MAXBUFFER 20
#define LEN sizeof(Elemtype)

typedef char Elemtype;
typedef struct {
	Elemtype* base;
	Elemtype* top;
	int StackSize;
}SqStack;

/*��ʼ��ջ*/
void InitStack(SqStack* S)
{
	S->base = (Elemtype*)malloc(LEN * INITSIZE);
	assert(S->base != NULL);
	S->top = S->base;
	S->StackSize = INITSIZE;
}

/*ѹջ����*/
void PushStack(SqStack* S, Elemtype c)
{
	if (S->top - S->base >= S->StackSize)
	{
		S->base = (Elemtype*)realloc(S->base, LEN * (S->StackSize + INCREMENT));
		assert(S->base != NULL);
		S->top = S->base + S->StackSize;
		S->StackSize += INCREMENT;
	}
	*S->top++ = c;
}

/*��ջ��*/
int StackLength(SqStack* S)
{
	return (S->top - S->base);
}
/*��ջ����*/
int PopStack(SqStack* S, Elemtype* c)
{
	if (!StackLength(S))
		return 0;
	*c = *--S->top;
	return 1;
}

/*��׺ת��׺����*/
Elemtype* Transform(SqStack* tran_stack, Elemtype str[])
{
	int i = 0, flag = 0;
	Elemtype* output;
	output = (Elemtype*)malloc(sizeof(Elemtype) * MAXBUFFER);
	Elemtype temp;
	InitStack(tran_stack);
	while (str[i] != '\0')
	{
		while (isdigit(str[i]))
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			output[flag++] = str[i++];
		}
		/*�Ӽ���������ȼ���ͣ����ջ��Ԫ��Ϊ����ֱ����ջ������ջ�д洢
		�������ȫ����ջ�����������������ֹͣ���������������Ŵ���ѹջ����Ϊ��
		����Ҫ��������ƥ��ʱ���������������ȼ��͵������ѹ��ջ��*/
		if (str[i] == '+' || str[i] == '-')
		{
			if (!StackLength(tran_stack))
				PushStack(tran_stack, str[i]);
			else
			{
				do
				{
					PopStack(tran_stack, &temp);
					if (temp == '(')
						PushStack(tran_stack, temp);
					else
						output[flag++] = temp;
				} while (StackLength(tran_stack) && temp != '(');
				PushStack(tran_stack, str[i]);
			}
		}
		/*�������������ǣ���������ʣ��������������ֱ��ƥ�䵽������Ϊֹ
		������ֻ��������ӡ��������Ҳ��ѹջ��*/
		else if (str[i] == ')')
		{
			PopStack(tran_stack, &temp);
			while (temp != '(')
			{
				output[flag++] = temp;
				PopStack(tran_stack, &temp);
			}
		}
		/*�ˡ����������Ŷ������ȼ��ߵģ�ֱ��ѹջ*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
			PushStack(tran_stack, str[i]);
		else if (str[i] == '\0')
			break;
		i++;
	}
	/*����ջ��ʣ�����������ε�ջ��ӡ*/
	while (StackLength(tran_stack))
	{
		PopStack(tran_stack, &temp);
		output[flag++] = temp;
	}
	output[flag] = '\0';
	return output;
}

int calculate(char* str)
{

}

int main()
{
	Elemtype str[MAXBUFFER];
	SqStack S;
	char* output;
	int answer;
	gets_s(str);
	output = Transform(&S, str);
	printf("\n%s", output);
	answer = calculate(output);
	return 0;
}