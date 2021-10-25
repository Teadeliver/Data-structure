#include<stdio.h>

int main()
{
	int way[100010];
	int n, k, count=0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &k);
		if (count == 0 || way[count - 1] < k)
		{
			way[count++] = k;
		}
		else {
			int left = 0, right = count - 1;
			while (left < right)
			{
				int mid = left + right >> 1;
				if (way[mid] > k)
					right = mid;
				else 
					left = mid + 1;
			}
			way[left] = k;
		}
	}
	printf("%d", count);
}