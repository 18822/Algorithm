#include<stdio.h>
#include<string.h>

typedef struct Graph {
	int vertex;
	int edge;
	int adjacency_matrix[10][10];
}Graph;

Graph MyGraph;
void adjacency_matrix_init()
{
	int v, e, start, end, value;
	printf("please input the number of vertex and edge:\n");
	scanf("%d %d", &v, &e);
	MyGraph.edge = e;
	MyGraph.vertex = v;

	for (int i = 0; i < MyGraph.vertex; i++)
		for (int j = 0; j < MyGraph.vertex; j++)
		{
			if (i == j)
				MyGraph.adjacency_matrix[i][j] = 0;
			else
				MyGraph.adjacency_matrix[i][j] = +2147483600;
		}
	printf("please input the record:\n");
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &start, &end, &value);//get the exact infomation 
		MyGraph.adjacency_matrix[start][end] = value;
	}

}

void find_way(int a, int b,int P[10][10])
{
	if (P[a][b] == -1)
		printf("%d -> ",a);
	else
	{
		find_way(a,P[a][b],P);
		find_way(P[a][b],b,P);
	}
}

void Floyd()
{
	int D[10][10], P[10][10];
	for (int i = 0; i < MyGraph.vertex; i++)
		for (int j = 0; j < MyGraph.vertex; j++)
			D[i][j] = MyGraph.adjacency_matrix[i][j];

	for (int i = 0; i < MyGraph.vertex; i++)
		for (int j = 0; j < MyGraph.vertex; j++)
			P[i][j] = -1;
	
	for(int k = 0;k < MyGraph.vertex;k++)
		for(int i = 0;i < MyGraph.vertex;i++)
			for (int j = 0; j < MyGraph.vertex; j++)
				if (D[i][j] > D[i][k] + D[k][j])
				{
					D[i][j] = D[i][k] + D[k][j];
					P[i][j] = k;
				}
	for (int i = 0; i < MyGraph.vertex; i++)
	{
		for (int j = 0; j < MyGraph.vertex; j++)
		{
			if (i != j)
			{
				printf("the value of shortest way from node %d to node %d is %d\n", i, j, D[i][j]);
				
				find_way(i, j, P);
				printf("%d", j);
				printf("\n");
			}

		}
	}

}


int main()
{
	adjacency_matrix_init();
	Floyd();
}
