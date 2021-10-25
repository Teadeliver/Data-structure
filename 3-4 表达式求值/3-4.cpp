#include<stdio.h>
#include<stdlib.h>
#include<ctype.h> 
#include<assert.h>

#define INITSIZE 30
#define INCREMENT 10
#define MAXBUFFER 30
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

/*��׺���ʽת��׺���ʽ*/
Elemtype* Transform(SqStack* tran_stack, Elemtype str[])
{
	int i = 0, flag = 0;
	int pp = 0;
	Elemtype* output;
	output = (Elemtype*)malloc(sizeof(Elemtype) * MAXBUFFER);
	Elemtype temp;
	InitStack(tran_stack);
	while (str[i] != '\0')
	{
		pp = 0;
		while (isdigit(str[i]))
		{/*���������ַ���ֱ�������ֱ����һλ���������ַ���ӡ�ո�����ѭ�� */
			output[flag++] = str[i++];
			pp = 1;
		}
		if (pp == 1)//�ָ����֣�pp�������Ǳ�ʶ�Ƿ����������
			output[flag++] = '#';
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

//��׺���ʽ����
int calculate(char* output)
{
	int i = 0, num3;
	int num1, num2;

	int number[MAXBUFFER];
	int top = 0;

	while (output[i] != '\0')
	{
		number[top] = atoi(output+i);
		top++;
		while (output[i] != '#')
		{
			i++;
			if (output[i] == '#')
			{
				i++;
				break;
			}
		}
		if (output[i] == '+')
		{
			num1 = number[--top];
			num2 = number[--top];
			num3 = num1 + num2;
			number[top++] = num3;
		}
		if (output[i] == '-')
		{
			num1 = number[--top];
			num2 = number[--top];
			num3 = num1 - num2;
			number[top++] = num3;
		}
		if (output[i] == '*')
		{
			num1 = number[--top];
			num2 = number[--top];
			num3 = num1 * num2;
			number[top++] = num3;
		}
		if (output[i] == '/')
		{
			num1 = number[--top];
			num2 = number[--top];
			num3 = num1 / num2;
			number[top++] = num3;
		}
	}
	return number[top];
}

int main()
{
	Elemtype input[MAXBUFFER];
	SqStack S;
	char* output;
	int answer;
	gets_s(input);
	output = Transform(&S, input);
	answer = calculate(output);
	printf("%d", answer);
	return 0;
}