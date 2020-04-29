#include<stdio.h>

typedef struct node{
    int s;
    int f;
    int choose;
}node;

int main()
{
    int n;
    node tar[100];
    printf("Please input the amount of the activities:\n");
    scanf("%d",&n);
    for(int i = 0;i < n;i++)
    {
        printf("Please input the start and end time of %d\n",i+1);
        scanf("%d %d",&tar[i].s,&tar[i].f);

        tar[i].choose = 0;
    }

    for(int i = 0;i < n;i++)
        for(int j = i;j < n;j++)
        {
            if(tar[i].f > tar[j].f)
            {
                int ftmp = tar[i].f;
                int stmp = tar[i].s;
                tar[i].f = tar[j].f;
                tar[i].s = tar[j].s;
                tar[j].f = ftmp;
                tar[j].s = stmp;
            }

        }

    int sep = 0;
    for(int i = 0;i < n;i++)
    {
        if(tar[i].s >= sep)
        {
            tar[i].choose = 1;
            sep = tar[i].f;
        }

    }
    int index = 1;
    for(int i = 0;i < n;i++)
    {
        if(tar[i].choose == 1)
        {
            printf("the %d chosen activity start at %d end at %d\n",index,tar[i].s,tar[i].f);
            index ++;
        }
    }

}

