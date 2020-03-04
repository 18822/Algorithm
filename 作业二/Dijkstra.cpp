#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node {
	int index;//the index of the vertex
	int value;//the value of the edge
	struct Node* next;
}Node;

typedef struct Graph {
	int vertex;//the amount of the vertex in Graph
	int edge;//the amount of the edge in Graph
	Node content[100];
}Graph;

typedef struct Edge {
	int start;//the start point of the edge
	int end;//the end point of the edge
	int value;//the value of the edge
}Edge;

typedef struct Dijk_Node {
	int value;
	int path;
	int visited;
}Dijk_Node;

Graph Directed_Graph_init()
{
	Graph MyGraph;
	int v, e, start, end, value;
	memset(MyGraph.content, 0, sizeof(Node) * 100);
	printf("please input the number of vertex and edge:\n");
	scanf("%d %d", &v, &e);
	MyGraph.edge = e;
	MyGraph.vertex = v;
	for (int i = 0; i < v; i++)
		MyGraph.content[i].next = NULL;

	printf("please input the record:\n");
	for (int i = 0; i < e; i++)
	{
		scanf("%d %d %d", &start, &end, &value);//get the exact infomation 

		Node* tmp1 = (Node*)malloc(sizeof(Node));//from start to end
		tmp1->index = end;
		tmp1->value = value;
		tmp1->next = MyGraph.content[start].next;
		MyGraph.content[start].next = tmp1;
	}
	return MyGraph;
}

void Dijkstra(Graph G)
{
	Dijk_Node dist[100];
	int start;
	for (int i = 0; i < G.vertex; i++)
	{
		dist[i].path = 0;
		dist[i].value = 2147483647;//equal to infinity
		dist[i].visited = 0;
	}//this loop initialize the dist
	printf("please input the index you want to start:\n");
	scanf("%d", &start);
	dist[start].value = 0;
	
	while (1)
	{
		int min = 2147483647;
		int Vmin = 0;//record the vertex selected
		for (int i = 0; i < G.vertex; i++)
		{
			if (dist[i].visited == 0 && dist[i].value < min)
			{
				min = dist[i].value;
				Vmin = i;
			}
		}
		if (min == 2147483647)
			break;
		else
			dist[Vmin].visited = 1;
		for (Node* tmp = G.content[Vmin].next; tmp != NULL; tmp = tmp->next)
		{
			if(dist[tmp->index].visited == 0)
				if (dist[Vmin].value + tmp->value < dist[tmp->index].value)
				{
					dist[tmp->index].value = dist[Vmin].value + tmp->value;
					dist[tmp->index].path = Vmin;
				}
		}
	}
	for (int i = G.vertex-1; i >= 0; i--)
	{
		if (i != start)
		{
			printf("the shortest path from %d to %d:\n", start, i);
			int tmp = i;
			while (tmp != start)
			{
				printf("%d<-", tmp);
				tmp = dist[tmp].path;
			}
			printf("%d\n",start);
		}
	}
}

int main()
{
	Graph G;
	G = Directed_Graph_init();
	Dijkstra(G);
}
