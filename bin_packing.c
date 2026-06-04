#include <stdio.h>

void binPacking(int weights[], int n, int capacity)
{
    int binCount = 0;
    int remaining[100];

    for(int i = 0; i < n; i++)
    {
        int placed = 0;

        for(int j = 0; j < binCount; j++)
        {
            if(remaining[j] >= weights[i])
            {
                remaining[j] -= weights[i];
                placed = 1;
                break;
            }
        }

        if(!placed)
        {
            remaining[binCount] = capacity - weights[i];
            binCount++;
        }
    }

    printf("\nMinimum bins required = %d\n", binCount);
}

int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weights[n];

    printf("Enter weights of items:\n");
    for(int i = 0; i < n; i++)
        scanf("%d", &weights[i]);

    printf("Enter bin capacity: ");
    scanf("%d", &capacity);

    binPacking(weights, n, capacity);

    return 0;
}