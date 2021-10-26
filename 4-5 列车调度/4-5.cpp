#include<stdio.h>

int main()
{
	int way[100010];
	int n, car_num, count = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &car_num);
		if (count == 0 || way[count - 1] < car_num)
		{
			way[count++] = car_num;
		}
		else {
			int left = 0, right = count - 1;
			while (left < right)
			{
				/*使用移位操作符提高效率
				left + right >> 1;在数学上等同于left + right / 2;
				但是效率在运行次数较多时有相当可观的提升*/
				int mid = left + right >> 1;
				if (way[mid] > car_num)
					right = mid;
				else
					left = mid + 1;
			}
			way[left] = car_num;
		}
	}
	printf("%d", count);
}