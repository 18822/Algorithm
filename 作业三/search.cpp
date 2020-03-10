#include<stdio.h>


int Sequential_Search(int data[],int n,int number)
{
	for(int i = 0;i < n;i++)
		if(number == data[i])
		{
			printf("the index of the number you search is %d",i);
			return i;
		}
	
	printf("the number you search doesn't exist");	
	return -1;
}

int Binary_Search(int data[],int n,int number)
{
	int low,high,mid;
	low = 0;
	high = n-1;
	while(low < high)
	{
		mid = (low+high)/2;
		if(data[mid] == number)
		{
			printf("the index of the number you search is %d",mid);
			return mid;
		}
		else if(data[mid] < number)
			low = mid +1;
		else if(data[mid] > number)
			high = mid -1;
	}
	printf("the number you search doesn't exist'");
	return -1;
}

int main()
{
	int data[100];
	int n,aim;
	printf("Please input the amount of data(less than 100):\n");
	scanf("%d",&n);
	if(n > 100)
		return 0;
	printf("Please input the data:\n");
	for(int i = 0;i < n;i++)
		scanf("%d",&data[i]);
	printf("Please input the number you want to search:\n");
	scanf("%d",&aim);
	Binary_Search(data,n,aim);
}
