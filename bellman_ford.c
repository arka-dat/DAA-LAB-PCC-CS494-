#include <stdio.h>

#define INF 99999

void bellmanFord(int graph[100][100], int n, int source)
{
    int dist[100];


    for(int i = 0; i < n; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(int k = 1; k <= n - 1; k++)
    {
        for(int u = 0; u < n; u++)
        {
            for(int v = 0; v < n; v++)
            {
                if(graph[u][v] != 0 && dist[u] != INF)
                {
                    if(dist[u] + graph[u][v] < dist[v])
                    {
                        dist[v] = dist[u] + graph[u][v];
                    }
                }
            }
        }
    }

    for(int u = 0; u < n; u++)
    {
        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] != 0 && dist[u] != INF)
            {
                if(dist[u] + graph[u][v] < dist[v])
                {
                    printf("Negative weight cycle detected!\n");
                    return;
                }
            }
        }
    }

    printf("\nShortest Distances:\n");

    for(int i = 0; i < n; i++)
        printf("%d -> %d = %d\n", source, i, dist[i]);
}

int main()
{
    int n, source;
    int graph[100][100];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            scanf("%d", &graph[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(graph, n, source);

    return 0;
}