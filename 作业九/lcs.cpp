#include<stdio.h>
#include<stack>
using namespace std;
#define BOTH 0
#define LEFT 1
#define RIGHT 2

int C[10][10],B[10][10];
stack <int>stk;

void lcs(int first[10],int fn,int second[10],int sn)
{
    for(int i = 1;i <= fn;i++)
        C[i][0] = 0;
    for(int j = 0;j <= sn;j++)
        C[0][j] = 0;
    for(int i = 1;i <= fn;i++)
        for(int j = 1;j <= sn;j++)
        {
            if(first[i-1] == second[j-1])
            {
                B[i][j] = BOTH;
                C[i][j] = C[i-1][j-1]+1;
            }
            else
            {
                if(C[i][j-1] >= C[i-1][j])
                {
                    C[i][j] = C[i][j-1];
                    B[i][j] = LEFT ;//delete x
                }
                else
                {
                    C[i][j] = C[i-1][j];
                    B[i][j] = RIGHT ;//delete y
                }
            }

        }
}

void lcsfind(int B[10][10],int i ,int j)
{
    if(i == 0 || j == 0)
        return ;
    if(B[i][j] == BOTH)
    {
        stk.push(i);
        lcsfind(B,i-1,j-1);
    }
    else if(B[i][j] == LEFT)
        lcsfind(B,i,j-1);
    else
        lcsfind(B,i-1,j);
}
int main()
{
    int first[10],second[10];
    int fn,sn;



    printf("Please input the amount of first sequence:\n");
    scanf("%d",&fn);
    printf("Please input the first sequence:\n");
    for(int i = 0;i < fn;i++)
        scanf("%d",&first[i]);
    printf("Please input the amount of second sequence:\n");
    scanf("%d",&sn);
    printf("Please input the second sequence:\n");
    for(int i = 0;i < sn;i++)
        scanf("%d",&second[i]);

    lcs(first,fn,second,sn);

    lcsfind(B,fn,sn);
    printf("the length of the sequence is %d\n",C[fn][sn]);
    printf("the sequence is:");
    while(!stk.empty())
    {
        printf("%d ",first[stk.top()-1]);
        stk.pop();
    }

}

