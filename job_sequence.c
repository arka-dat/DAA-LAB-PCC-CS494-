#include <stdio.h>

typedef struct {
    int id;
    int profit;
    int deadline;
} Job;

void swap(Job *a, Job *b) {
    Job temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(Job arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j].profit < arr[j + 1].profit) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    printf("Enter number of jobs: ");
    scanf("%d", &n);

    Job jobs[n];
    
    for (int i = 0; i < n; i++) {
        jobs[i].id = i + 1;
        printf("Enter profit and deadline for job %d: ", i + 1);
        scanf("%d %d", &jobs[i].profit, &jobs[i].deadline);
    }

    bubbleSort(jobs, n);

    int maxDeadline = 0;
    for (int i = 0; i < n; i++) {
        if (jobs[i].deadline > maxDeadline)
            maxDeadline = jobs[i].deadline;
    }

    int slot[maxDeadline];
    for (int i = 0; i < maxDeadline; i++)
        slot[i] = -1;

    int totalProfit = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline - 1; j >= 0; j--) {
            if (slot[j] == -1) {
                slot[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\nSelected Jobs (in order of slots): ");
    for (int i = 0; i < maxDeadline; i++) {
        if (slot[i] != -1)
            printf("Job%d ", slot[i]);
    }

    printf("\nTotal Profit: %d\n", totalProfit);

    return 0;
}