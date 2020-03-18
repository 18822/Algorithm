#include<stdio.h>

void Merge(int T[], int left1, int right1, int left2, int right2)
{
	char tmp[50] = {0};
	int index = 0, start = left1;
	int length = right2 - left1 + 1;
	while (index < length)
	{
		if (left2 > right2)
		{
			while (index < length)
				tmp[index++] = T[left1++];
			break;
		}
		else if (left1 > right1)
		{
			while (index < length)
				tmp[index++] = T[left2++];
			break;
		}
		else if (T[left1] < T[left2] )
			tmp[index++] = T[left1++];
		else if (T[left2] < T[left1] )
			tmp[index++] = T[left2++];
	}
	for (int i = 0; i < length; i++)
		T[start + i] = tmp[i];
}

void MergeSort(int T[], int left, int right)
{
	if (left == right)
		return;
	else
	{
		int mid = (left + right) / 2;
		MergeSort(T, left, mid);
		MergeSort(T, mid + 1, right);
		Merge(T, left, mid, mid + 1, right);
	}
}



int main()
{
	int n;
	int Array[100];
	printf("Please input the amount of number:\n");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &Array[i]);
	MergeSort(Array, 0, n - 1);
	printf("the result after sort\n");
	for (int i = 0; i < n; i++)
		printf("%d ", Array[i]);

}
