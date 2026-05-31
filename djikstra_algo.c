#include <stdio.h>

#define INF 99999

void dijkstra(int graph[100][100], int n, int source)
{
    int dist[100], visited[100];

    for(int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    for(int k = 0; k < n - 1; k++)
    {
        int min = INF;
        int u = -1;

        for(int i = 0; i < n; i++)
        {
            if(visited[i] == 0 && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        visited[u] = 1;

        for(int v = 0; v < n; v++)
        {
            if(graph[u][v] != 0 && visited[v] == 0)
            {
                if(dist[u] + graph[u][v] < dist[v])
                    dist[v] = dist[u] + graph[u][v];
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

    dijkstra(graph, n, source);

    return 0;
}