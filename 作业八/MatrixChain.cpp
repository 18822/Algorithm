#include<stdio.h>
int m[10][10],s[10][10];

void Matrix(int P[100],int n)
{
    for(int i = 1;i <= n;i++)
        m[i][i] = 0;
    for(int r = 2;r <= n;r++)
    {
        for(int i = 1;i <= n-r+1;i++)
        {
            int j = i+r-1;
            m[i][j] = m[i+1][j]+P[i-1]*P[i]*P[j];
            s[i][j] = i;
            for(int k = i+1;k<=j-1;k++)
            {
                int t = m[i][k]+m[k+1][j]+P[i-1]*P[k]*P[j];
                if(t < m[i][j])
                {
                    m[i][j] = t;
                    s[i][j] = k;
                }
            }
        }
    }
}


int main()
{
    int P[100];
    int n;
    printf("Please input the number of matrix:\n");
    scanf("%d",&n);
    printf("Please input the rank vector of the matrix:\n");
    for(int i = 0;i <= n;i++)
        scanf("%d",&P[i]);
    Matrix(P,n);

}

