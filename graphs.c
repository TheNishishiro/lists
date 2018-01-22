#include <limits.h>

#include "graphs.h"
#include "listy.h"
#include "listyPrior.h"

int* CreateGraphArray(int n)
{
	int m, i, j, k1, k2;
	int *M; 
	printf("Insert number of connections:\n");
	scanf("%d", &m);
	M = malloc(sizeof(int) * n * n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			M[n * i + j] = 0;
	
	for(i = 0; i < m; i++)
	{
		printf("Insert connection between two points:\n");
		scanf("%d %d", &k1, &k2);
		M[n * (k1-1) + (k2-1)] = 1;
	}
	
	return M;
}

void PrintGraphArray(int* graph, int n)
{
	int i, j;
	for(i = 0; i < n; i++)
	{
		for(j = 0; j < n; j++)
			printf("%d", graph[n * i + j]);
		printf("\n");
	}
}

void PrintGraphList(lista* graph, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d: ", i + 1);
		PrintList(graph[i]);
	}
}

int* ConvertGraphListToArray(lista* graph, int n)
{
	int m, i, j;
	int *M; 
	lista g;
	M = malloc(sizeof(int) * n * n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			M[n * i + j] = 0;

	for(i = 0; i < n; i++)
	{
		g = graph[i];
		while(graph[i])
		{
			j = graph[i]->klucz;
			M[n * i + (j-1)] = 1;
			graph[i] = graph[i]->nast;
		}
		graph[i] = g;
	}
	
	return M;
}

lista* CreateGraphList(int n)
{
	int m, i, j, k1, k2;
	lista *M; 
	printf("Insert number of points and connections:\n");
	scanf("%d", &m);
	M = malloc(sizeof(lista) * n);
	for(i = 0; i < n; i++)
		M[i] = 0;
	
	for(i = 0; i < m; i++)
	{
		printf("Insert connection between two points:\n");
		scanf("%d %d", &k1, &k2);
		AddElementSorted(&M[k1-1], k2);
	}
	
	return M;
}

lista* CreateGraphReversed(lista* graph, int n)
{
	int m, i, j, found = 0;
	lista *M; 
	M = malloc(sizeof(lista) * n);
	for(i = 0; i < n; i++)
		M[i] = 0;
	lista g;	
	for(i = 0; i < n; i++)
	{
		for(j = 1; j <= n; j++)
		{
			found = 0;
			g = graph[i];
			while(graph[i])
			{
				if(graph[i]->klucz == j)
				{
					found = 1;
					break;
				}
				else
				{
					graph[i] = graph[i]->nast;
				}
			}
			graph[i] = g;
			if(found == 0)
				AddElementSorted(&M[i], j);
		}
	}
	
	printf("GRAPH: \n");
	PrintGraphList(graph, n);
	printf("REVERSED: \n");
	PrintGraphList(M, n);
	return M;
}

// =======================================================================

listaPrior* CreateGraphListPrior(int n)
{
	int m, i, j, k1, k2, k3;
	listaPrior *M; 
	printf("Insert number of points and connections:\n");
	scanf("%d", &m);
	M = malloc(sizeof(listaPrior) * n);
	for(i = 0; i < n; i++)
		M[i] = 0;
	
	for(i = 0; i < m; i++)
	{
		printf("Insert connection between two points and priority:\n");
		scanf("%d %d %d", &k1, &k2, &k3);
		AddElementSortedPrior(&M[k1], k2, k3);
	}
	
	return M;
}

void PrintGraphListPrior(listaPrior* graph, int n)
{
	int i;
	for(i = 0; i < n; i++)
	{
		printf("%d: ", i);
		PrintListPrior(graph[i]);
	}
}

int *d, *p; 

void Init_Single_Source(int n, int s)
{
	int i = 0;
	d = malloc(sizeof(int) * n);
	p = malloc(sizeof(int) * n);
	
	for(i = 0; i < n; i++)
	{
		d[i] = INT_MAX;
		p[i] = -1;
	}
	d[s] = 0;
}

void Relax(int u, int v, int w, listaPrior *Q)
{
	if(d[v] > d[u] + w)
	{
		d[v] = d[u] + w;
		p[v] = u;
		RearrangePriorList(Q, v, d[v]);
	}
}

void Dijkstra(listaPrior* graph, int n, int source, int destination)
{
	int i = 0;
	int u = 0;
	Init_Single_Source(n, source);
	
	listaPrior Q = 0;
	
	for(i = 0; i < n; i++)
		AddElementSortedPriorReverse(&Q, i, d[i]);
		
	while(Q)
	{
		u = GetFirstKeyAndRemove(&Q);	
		listaPrior S = graph[u];
		while(S)
		{
			Relax(u, S->klucz, S->priorytet, &Q);
			S = S->nast;
		}
	}
	int w = destination;
	while(w != -1)
	{
		printf(" <- %d", w);
		w = p[w];
	}
}


