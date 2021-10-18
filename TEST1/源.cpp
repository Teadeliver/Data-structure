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

/*初始化栈*/
void InitStack(SqStack* S)
{
	S->base = (Elemtype*)malloc(LEN * INITSIZE);
	assert(S->base != NULL);
	S->top = S->base;
	S->StackSize = INITSIZE;
}

/*压栈操作*/
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

/*求栈长*/
int StackLength(SqStack* S)
{
	return (S->top - S->base);
}
/*弹栈操作*/
int PopStack(SqStack* S, Elemtype* c)
{
	if (!StackLength(S))
		return 0;
	*c = *--S->top;
	return 1;
}

/*中缀转后缀函数*/
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
		{/*过滤数字字符，直接输出，直到下一位不是数字字符打印空格跳出循环 */
			output[flag++] = str[i++];
		}
		/*加减运算符优先级最低，如果栈顶元素为空则直接入栈，否则将栈中存储
		的运算符全部弹栈，如果遇到左括号则停止，将弹出的左括号从新压栈，因为左
		括号要和右括号匹配时弹出。弹出后将优先级低的运算符压入栈中*/
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
		/*当遇到右括号是，把括号里剩余的运算符弹出，直到匹配到左括号为止
		左括号只弹出不打印（右括号也不压栈）*/
		else if (str[i] == ')')
		{
			PopStack(tran_stack, &temp);
			while (temp != '(')
			{
				output[flag++] = temp;
				PopStack(tran_stack, &temp);
			}
		}
		/*乘、除、左括号都是优先级高的，直接压栈*/
		else if (str[i] == '*' || str[i] == '/' || str[i] == '(')
			PushStack(tran_stack, str[i]);
		else if (str[i] == '\0')
			break;
		i++;
	}
	/*最后把栈中剩余的运算符依次弹栈打印*/
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