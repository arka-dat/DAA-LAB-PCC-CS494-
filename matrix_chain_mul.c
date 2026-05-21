#include <stdio.h>

int matrixChain(int p[], int n)
{
    int dp[n][n];
    int s[n][n];
    for(int i = 1; i < n; i++)
    {
        dp[i][i] = 0;
        for(int j = 1; j < n; j++)
        {
            s[i][j] = 0;
        }
    }
    
    for(int len = 2; len < n; len++)
    {
        for(int i = 1; i < n - len + 1; i++)
        {
            int j = i + len - 1;

            dp[i][j] = 10000000;

            for(int k = i; k < j; k++)
            {
                int cost = dp[i][k]
                         + dp[k + 1][j]
                         + p[i - 1] * p[k] * p[j];

                if(cost < dp[i][j])
                {
                    dp[i][j] = cost;
                    s[i][j] = k;
                }
            }
        }
    }

    printf("\nDP Table (Minimum Costs):\n\n");
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(j < i)
                printf("-\t");
            else
                printf("%d\t", dp[i][j]);
        }
        printf("\n");
    }

    printf("\nSplit Table (Optimal k-values):\n\n");
    for(int i = 1; i < n; i++)
    {
        for(int j = 1; j < n; j++)
        {
            if(j <= i)
                printf("-\t");
            else
                printf("%d\t", s[i][j]);
        }
        printf("\n");
    }

    return dp[1][n - 1];
}

int main()
{
    int n;

    printf("Enter number of matrices: ");
    scanf("%d", &n);

    int p[n + 1];

    printf("Enter dimensions array:\n");

    for(int i = 0; i <= n; i++)
    {
        scanf("%d", &p[i]);
    }

    int result = matrixChain(p, n + 1);

    printf("\nMinimum number of multiplications = %d\n", result);

    return 0;
}