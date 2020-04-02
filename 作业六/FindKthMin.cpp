#include<stdio.h>
#include<string.h>
class arr{

	public:
		void add(int n)
		{
			this->content[this->index] = n;
			this->index ++;
		}
        arr()
        {
            memset(this->content,0,100);
            this->index = 0;
        }
        int length()
        {
            return this->index;
        }

		int index = 0;
		int content[100];
};

void MySwap(int *a,int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void MySort(int a[100],int st,int end)
{
    for(int i = st;i < end;i++)
        for(int j = st;j < end;j++)
            if(a[i]<a[j])
                MySwap(&a[i],&a[j]);
}

void Swap5(int a[100],int x,int y)
{
    for(int i = 0;i < 5;i++)
    {
        MySwap(&a[x-2+i],&a[y-2+i]);
    }
}

int FindKthMin(int L[100],int k,int n)
{
    for(int i = 0;i < n/5;i++)
        MySort(L,i*5,i*5+5);
    MySort(L,(n/5)*5,n);
    for(int i = 2;i < n;i+=5)
        for(int j = i;j < n;j+=5)
        {
            if(L[j] < L[i])
                Swap5(L,i,j);
        }
    arr S1,S2;
    int m_index = (n/5)/2*5+2;
    int m = L[m_index];

    for(int i = 0;i <= (n/5)/2;i++)
        for(int j = 0;j < 3;j++)
            if(i*5+j != m_index)
                S1.add(L[i*5+j]);

	for(int i = (n/5)/2;i < n/5;i++)
		for(int j = 2;j < 5;j++)
			if(i*5+j != m_index)
				S2.add(L[i*5+j]);

	for(int i = 0;i < (n/5)/2;i++)
		for(int j = 3;j < 5;j++)
		{
			if(L[i*5+j] < m)
				S1.add(L[i*5+j]);
			else
				S2.add(L[i*5+j]);
		}

	for(int i = (n/5)/2+1;i < (n/5);i++)
		for(int j = 0;j < 2;j++)
		{
			if(L[i*5+j] < m)
				S1.add(L[i*5+j]);
			else
				S2.add(L[i*5+j]);
		}

	for(int i = (n/5)*5;i < n;i++)
	{
		if(L[i] < m)
			S1.add(L[i]);
		else
			S2.add(L[i]);
	}

	if(S1.length()+1 == k)
        return m;
    else if(S1.length()+1 < k)
        FindKthMin(S2.content,k-S1.length()-1,S2.length());
    else
        FindKthMin(S1.content,k,S1.length());

}


int main()
{
        int n,k,a[100];
        printf("Please input the amount of your input:\n");
        scanf("%d",&n);
        printf("Please input the content:\n");
        for(int i = 0;i < n;i++)
        {
            scanf("%d",&a[i]);
        }
        printf("Please input the index:\n");
        scanf("%d",&k);

        int re = FindKthMin(a,k,n);
        printf("the %dth number is %d",k,re);
        return 0;
}

