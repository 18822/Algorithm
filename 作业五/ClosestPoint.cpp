#include<stdio.h>
#include<math.h>
#define Inf 21474
typedef struct Point{
	int x;
	int y;
}Point;

void swap(Point* a,Point* b)
{
	Point p = *a;
	*a = *b;
	*b = p;
}

double cal(Point a,Point b)
{
	return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}

double mini(double a,double b)
{
	if(a > b)
		return b;
	else
		return a;
}

void PointSort(Point a[100],int start,int end)
{
	if(start < end)
	{
		int i = start;
		int j = i+1;
		for(j;j <= end;j++)
		{
			if(a[j].x < a[start].x)
			{
				swap(&a[++i],&a[j]);
			}
		}
		swap(&a[i],&a[start]);
		PointSort(a,start,i-1);
		PointSort(a,i+1,end);
	}
}

double FindClosestPoint(Point a[100],int start,int end)
{
	int amount = end-start+1;
	int mid = (start+end)/2;
	double middle = (a[start].x + a[end].x)/2.0;
	if(amount == 2)
		return cal(a[start],a[end]);
	else if(amount == 1)
		return Inf;
	else if(amount > 0)
	{
		double dist1 = FindClosestPoint(a,start,mid);
		double dist2 = FindClosestPoint(a,mid+1,end);
		double dist = mini(dist1,dist2);
		double thisdist = Inf;
		for(int i = start;i <= end;i++)
			for(int j = start;j <= end;j++)
			{
				if((a[i].x <= a[mid].x && a[i].x >= a[mid].x - dist)
				&& (a[j].x >= a[mid].x && a[j].x <= a[mid].x + dist) && i!=j)
				{
					double dis = cal(a[i],a[j]);
					if(dis < thisdist)
						thisdist = dis;
				}
			}

		dist = mini(dist,thisdist);
		return dist;
	}
}

int main()
{
	int n,x,y;
	double dist;
	Point tar[100];
	printf("please input the number of point:\n");
	scanf("%d",&n);
	for(int i = 0;i < n;i++)
	{
		scanf("%d %d",&x,&y);
		tar[i].x = x;
		tar[i].y = y;
	}

	PointSort(tar,0,n);
	dist = FindClosestPoint(tar,0,n-1);
	printf("%f",dist);
}

