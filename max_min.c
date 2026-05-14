#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to return both max and min
struct Pair {
    int min;
    int max;
};

/* Divide and Conquer function to find Max and Min */
struct Pair getMinMax(int arr[], int low, int high) {
    struct Pair minmax, left, right;
    int mid;

    // Case 1: If there is only one element
    if (low == high) {
        minmax.max = arr[low];
        minmax.min = arr[low];
        return minmax;
    }

    // Case 2: If there are two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            minmax.max = arr[low];
            minmax.min = arr[high];
        } else {
            minmax.max = arr[high];
            minmax.min = arr[low];
        }
        return minmax;
    }

    // Case 3: More than two elements (Divide)
    mid = (low + high) / 2;
    left = getMinMax(arr, low, mid);
    right = getMinMax(arr, mid + 1, high);

    // Combine results (Conquer)
    if (left.max > right.max)
        minmax.max = left.max;
    else
        minmax.max = right.max;

    if (left.min < right.min)
        minmax.min = left.min;
    else
        minmax.min = right.min;

    return minmax;
}

int main() {
    int n;
    clock_t start, end;

    printf("Enter the number of elements to generate: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid input.\n");
        return 1;
    }

    // Allocate memory on the heap
    int *data = (int *)malloc(n * sizeof(int));
    if (data == NULL) {
        printf("Memory allocation failed!\n");
        return 1;
    }

    // Populate with random numbers
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        data[i] = rand() % 2000000; // Random range up to 2 million
    }

    printf("Finding Max and Min in %d elements...\n", n);

    // Timing the execution
    start = clock();
    struct Pair result = getMinMax(data, 0, n - 1);
    end = clock();

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\n--- RESULTS ---\n");
    printf("Minimum element: %d\n", result.min);
    printf("Maximum element: %d\n", result.max);
    printf("Time taken: %f seconds\n", cpu_time_used);

    free(data);
    return 0;
}