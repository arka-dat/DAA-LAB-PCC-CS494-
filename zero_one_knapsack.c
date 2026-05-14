#include <stdio.h>
#include <stdlib.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int n, W;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    int val[n], wt[n];

    printf("Enter values of the items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &val[i]);

    printf("Enter weights of the items:\n");
    for (int i = 0; i < n; i++) scanf("%d", &wt[i]);

    printf("Enter the maximum capacity of the knapsack: ");
    scanf("%d", &W);

    int **dp = (int **)malloc((n + 1) * sizeof(int *));
    for (int i = 0; i <= n; i++)
        dp[i] = (int *)malloc((W + 1) * sizeof(int));

    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (wt[i - 1] <= w) {
                dp[i][w] = max(val[i - 1] + dp[i - 1][w - wt[i - 1]], 
                               dp[i - 1][w]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    printf("\nMaximum value possible: %d\n", dp[n][W]);

    for (int i = 0; i <= n; i++) free(dp[i]);
    free(dp);

    return 0;
}