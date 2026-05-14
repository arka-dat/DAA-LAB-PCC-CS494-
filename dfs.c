#include<stdio.h>
#include<stdlib.h>

int n;

void DFS(int node, int adj[n][n], int tag[n])
{
    printf("%d ", node);
    tag[node] = 1;

    for(int i = 0; i < n; i++)
    {
        if(adj[node][i] == 1 && tag[i] == -1)
        {
            DFS(i, adj, tag);
        }
    }
}

int main()
{
    printf("Enter no of nodes: ");
    scanf("%d", &n);

    int adj[n][n];

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("Enter value of [%d][%d] (1 if connected else 0): ", i, j);
            scanf("%d", &adj[i][j]);
        }
    }
    
     printf("\nAdjacency Matrix:\n");

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            printf("%d ", adj[i][j]);
        }
        printf("\n");
    }


    int tag[n];

    for(int i = 0; i < n; i++)
    {
        tag[i] = -1;
    }

    int start;

    printf("Enter starting node: ");
    scanf("%d", &start);

    printf("DFS Traversal: ");
    DFS(start, adj, tag);

    return 0;
}