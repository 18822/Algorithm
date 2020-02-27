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

Graph Undirected_Graph_init()
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

		Node* tmp2 = (Node*)malloc(sizeof(Node));//from end to start
		tmp2->index = start;
		tmp2->value = value;
		tmp2->next = MyGraph.content[end].next;
		MyGraph.content[end].next = tmp2;
	}
	return MyGraph;
}

int NotIn(int* a, int test)
{
	for (int i = 0; a[i] != -1; i++)
	{
		if (a[i] == test)
			return 0;
	}
	return 1;
}

void PRIM(Graph G)
{
	int init;
	int Vnew[100];//record the vertex that has been used
	Edge Enew[150];//record the edge that has been used
	int Vnum = 0;//record the number of the vertex that has been used
	int Enum = 0;//record the number of the edge that has been used

	memset(Vnew, -1, sizeof(int) * 100);
	memset(Enew, 0, sizeof(Edge) * 100);

	do
	{
		printf("Choose a index of the vertex:\n");
		scanf("%d", &init);
	} while (init < 0 || init >= G.vertex);
	Vnew[Vnum++] = init;

	while (Vnum != G.vertex)
	{
		int min = 2147483647;//record the min value of the edge for each loop
		int start = 0;
		int end = 0;

		for (int i = 0; Vnew[i] != -1; i++)
		{
			for (Node* tmp = G.content[Vnew[i]].next; tmp != NULL; tmp = tmp->next)
			{
				if (tmp->value < min && NotIn(Vnew, tmp->index))
				{
					min = tmp->value;
					start = Vnew[i];
					end = tmp->index;
				}
			}
		}

		Edge newEdge;
		newEdge.start = start;
		newEdge.end = end;
		Enew[Enum++] = newEdge;

		Vnew[Vnum++] = end;
	}
	printf("the edge of the new Graph:\n");
	for (int i = 0; i < G.vertex - 1; i++)
		printf("<%d,%d> ", Enew[i].start, Enew[i].end);
	//show the set of edge and vertex

}

void swap(Edge* a, Edge* b)
{
	Edge tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort_E(Edge* arr, int n)
{
	Edge re[150];
	for (int i = 0; i < n; i++)
		for (int j = i; j < n; j++)
			if (arr[i].value > arr[j].value)
				swap(&arr[i],&arr[j]);
}

int Find(int a,int* pre)
{
	return pre[a] != a ? Find(pre[a],pre) : pre[a];
}

void Kurskal(Graph G)
{
	int pre[100];
	int Vnew[100];
	int Vnum = 0;
	Edge Enew[150];
	int newNum = 0;
	Edge E[150];
	int Enum = 0;

	memset(Vnew, -1, sizeof(int) * 100);

	for (int i = 0; i < G.vertex; i++)
		pre[i] = i;

	for (int i = 0; i < G.vertex; i++)
	{
		for (Node* tmp = G.content[i].next; tmp != NULL; tmp = tmp->next)
		{
			if (tmp->index > i)
			{
				Edge newEdge;
				newEdge.start = i;
				newEdge.end = tmp->index;
				newEdge.value = tmp->value;
				E[Enum++] = newEdge;
			}
		}
	}
	sort_E(E, Enum);

	for (int i = 0; i < Enum; i++)
	{
		if (newNum == G.vertex - 1)
			break;
		if (Find(E[i].start,pre) != Find(E[i].end,pre))
		{
			pre[E[i].start] = E[i].end;
			Enew[newNum++] = E[i];
		}
	}
	printf("the edge of the new Graph:\n");
	for (int i = 0; i < G.vertex - 1; i++)
		printf("<%d,%d> ", Enew[i].start, Enew[i].end);
	//show
}

int main()
{
	Graph G = Undirected_Graph_init();
	//PRIM(G);
	Kurskal(G);
	return 0;
}

