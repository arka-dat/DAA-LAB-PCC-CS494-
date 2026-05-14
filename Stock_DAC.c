#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void findMinMax(int arr[], int low, int high, int *min, int *max);
void analyze_stock_windows_dc(int arr[], int size, int window_size);

int main() {
    int num_days = 10;
    int window_size = 3;

    // Allocate memory dynamically
    int *stocks = (int *)malloc(num_days * sizeof(int));
    
    // Seed the random number generator
    srand(time(NULL));

    // Generate random stock values between 10 and 100
    printf("Original chronological stock prices for %d days:\n", num_days);
    for (int i = 0; i < num_days; i++) {
        stocks[i] = (rand() % 91) + 10; 
        printf("%d ", stocks[i]);
    }
    printf("\n\n");

    // Apply the sliding window technique using Divide and Conquer
    // Notice we skipped the sorting step completely!
    analyze_stock_windows_dc(stocks, num_days, window_size);

    // Free the allocated memory
    free(stocks);

    return 0;
}

// Divide and Conquer function to find minimum and maximum in a given range
void findMinMax(int arr[], int low, int high, int *min, int *max) {
    int min1, max1, min2, max2;

    // Base case 1: If there is only one element
    if (low == high) {
        *min = arr[low];
        *max = arr[low];
        return;
    }

    // Base case 2: If there are exactly two elements
    if (high == low + 1) {
        if (arr[low] > arr[high]) {
            *max = arr[low];
            *min = arr[high];
        } else {
            *max = arr[high];
            *min = arr[low];
        }
        return;
    }

    // Recursive case: Divide the array (or window) into two halves
    int mid = low + (high - low) / 2;
    
    // Find min and max in the left half
    findMinMax(arr, low, mid, &min1, &max1);
    
    // Find min and max in the right half
    findMinMax(arr, mid + 1, high, &min2, &max2);

    // Conquer: Compare the minimums and maximums of the two halves
    if (min1 < min2) *min = min1;
    else *min = min2;

    if (max1 > max2) *max = max1;
    else *max = max2;
}

// Sliding window function
void analyze_stock_windows_dc(int arr[], int size, int window_size) {
    if (size < window_size) {
        printf("Error: Array size is smaller than the window size.\n");
        return;
    }

    printf("--- Sliding Window Analysis (Window Size: %d) ---\n", window_size);
    
    // Slide the window across the unsorted array
    for (int i = 0; i <= size - window_size; i++) {
        int current_min, current_max;
        
        // Pass the start (i) and end (i + window_size - 1) of the current window
        // into the divide and conquer function using pointers to extract the results
        findMinMax(arr, i, i + window_size - 1, &current_min, &current_max);
        
        int variation = current_max - current_min;

        // Print the results for this specific window
        printf("Window %d [ ", i + 1);
        for (int j = i; j < i + window_size; j++) {
            printf("%d ", arr[j]);
        }
        printf("] -> Min: %d | Max: %d | Variation: %d\n", current_min, current_max, variation);
    }
}