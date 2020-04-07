#include<stdio.h>
typedef struct point{
    int F;
    int x;
}point;
int invest[10][10];
point F[10][10];

int main()
{
    int m,n;
    printf("Please input the amount of money:\n");
    scanf("%d",&m);
    printf("Please input the amount of investment:\n");
    scanf("%d",&n);
    printf("Please input the mapping of the investment:\n");
    for(int i = 0;i < n;i++)
        for(int j = 0;j <= m;j++)
        {
            int num;
            scanf("%d",&num);
            invest[i][j] = num;
        }
    for(int i = 1;i <= m;i++)
    {
        F[0][i].F = invest[0][i];
        F[0][i].x = i;
    }
    for(int k = 1;k < n;k++)
        for(int x = 1;x <= m;x++)
        {
            int maxi = 0;
            int tmp;
            for(int xi = 0;xi <=x;xi++)
                if(invest[k][xi]+F[k-1][x-xi].F > maxi)
                {
                    maxi = invest[k][xi]+F[k-1][x-xi].F;
                    tmp = xi;
                }
            F[k][x].F = maxi;
            F[k][x].x = tmp;
        }
    printf("the best benefit is %d\n",F[n-1][m].F);
    int total = m;
    printf("and the investment plan are as followed:\n");
    for(int i = n-1;i >= 0;i--)
    {
        if(F[i][total].x != 0)
        {
            printf("invest %d in %dth project\n",F[i][total].x,i+1);
            total = total - F[i][total].x;
        }
    }


}

