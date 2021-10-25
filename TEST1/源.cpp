#include<stdio.h>
#include<stdlib.h>

#define Maxsize 100
typedef char ElemType;
typedef struct {
	ElemType base[Maxsize];
	int top;
}stackchar;

typedef struct {
	int base[Maxsize];
	int top;
}stackint;

int calculate(char x, int y, int z);

int main()
{
	int i = 0, j = 0;
	int y, z, b;
	char x;
	char a[Maxsize];
	stackchar s1;
	stackint s2;
	s1.top = -1;
	s2.top = -1;

	gets(a);

	while (a[j] != '\0') {

		//优先级为一
		if (a[j] == '+' || a[j] == '-') {
			if (s1.top == -1)
			{
				s1.top++;
				s1.base[s1.top] = a[j];
			}
			else {
				while (s1.base[s1.top] == '*' || s1.base[s1.top] == '/' || s1.base[s1.top] == '+' || s1.base[s1.top] == '-')
				{
					x = s1.base[s1.top];
					s1.top--;
					y = s2.base[s2.top];
					s2.top--;
					z = s2.base[s2.top];
					if (x == '/' && y == 0)
					{
						printf("ILLEGAL\n");
						exit(0);
					}
					s2.base[s2.top] = calculate(x, y, z);
				}
				s1.top++;
				s1.base[s1.top] = a[j];
			}
		}

		//优先级为二
		else if (a[j] == '*' || a[j] == '/') {
			if (s1.top == -1)
			{
				s1.top++;
				s1.base[s1.top] = a[j];
			}
			else {
				while (s1.base[s1.top] == '*' || s1.base[s1.top] == '/')
				{
					x = s1.base[s1.top];
					s1.top--;
					y = s2.base[s2.top];
					s2.top--;
					z = s2.base[s2.top];
					if (x == '/' && y == 0)
					{
						printf("ILLEGAL\n");
						exit(0);
					}
					s2.base[s2.top] = calculate(x, y, z);
				}
				s1.top++;
				s1.base[s1.top] = a[j];
			}
		}
		//优先级为三
		else if (a[j] == '(') {
			s1.top++;
			s1.base[s1.top] = a[j];
		}

		else if (a[j] == ')')
		{
			while (s1.base[s1.top] != '(')
			{
				x = s1.base[s1.top];
				s1.top--;
				y = s2.base[s2.top];
				s2.top--;
				z = s2.base[s2.top];
				if (x == '/' && y == 0)
				{
					printf("ILLEGAL\n");
					exit(0);
				}
				s2.base[s2.top] = calculate(x, y, z);
			}
			s1.top--;
		}

		//last
		else
		{
			b = a[j] - '0';
			if (a[j + 1] >= '0' && a[j + 1] <= '9')
			{
				j++;
				while (a[j] >= '0' && a[j] <= '9')
				{
					b = b * 10 + a[j] - '0';
					j++;
				}
				j--;
			}
			s2.top++;
			s2.base[s2.top] = b;
		}


		j++;
	}
	while (s1.top != -1)
	{
		x = s1.base[s1.top];
		s1.top--;
		y = s2.base[s2.top];
		s2.top--;
		z = s2.base[s2.top];
		if (x == '/' && y == 0)
		{
			printf("ILLEGAL\n");
			exit(0);
		}
		s2.base[s2.top] = calculate(x, y, z);
	}
	printf("%d\n", s2.base[s2.top]);
	return 0;
}

int calculate(char x, int y, int z)
{
	int sum = 0;
	switch (x)
	{
	case '+':
		sum = y + z;
		break;
	case '-':
		sum = z - y;
		break;
	case '*':
		sum = y * z;
		break;
	case '/':
		sum = z / y;
		break;
	}
	return sum;
}
