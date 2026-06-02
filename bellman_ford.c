#include <stdio.h>

#define INF 99999

void bellmanFord(int edge[][3], int v, int E, int source)
{
    int dist[100];

    for(int i = 0; i < v; i++)
        dist[i] = INF;

    dist[source] = 0;

    for(int i = 1; i <= v - 1; i++)
    {
        for(int j = 0; j < E; j++)
        {
            int U = edge[j][0];
            int V = edge[j][1];
            int W = edge[j][2];

            if(dist[U] != INF && dist[U] + W < dist[V])
                dist[V] = dist[U] + W;
        }
    }


    for(int j = 0; j < E; j++)
    {
        int U = edge[j][0];
        int V = edge[j][1];
        int W = edge[j][2];

        if(dist[U] != INF && dist[U] + W < dist[V])
        {
            printf("Negative Weight Cycle Detected\n");
            return;
        }
    }

    printf("\nVertex->Distance\n");
    for(int i = 0; i < v; i++)
        printf("%d->%d\n", i, dist[i]);
}

int main()
{
    int v, E, source;

    printf("Enter number of vertices: ");
    scanf("%d", &v);

    printf("Enter number of edges: ");
    scanf("%d", &E);

    int edge[E][3];

    printf("Enter Source Destination Weight:\n");
    for(int i = 0; i < E; i++)
        scanf("%d%d%d", &edge[i][0], &edge[i][1], &edge[i][2]);

    printf("Enter source vertex: ");
    scanf("%d", &source);

    bellmanFord(edge, v, E, source);

    return 0;
}
