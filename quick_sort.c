#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
    int i = low - 1;        

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); 

        quickSort(arr, low, pi - 1);  
        quickSort(arr, pi + 1, high); 
    }
}

int main() {
    int n;

    printf("Enter the number of elements: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Invalid array size.\n");
        return 1;
    }

    int *arr = (int *)malloc(n * sizeof(int));
    srand(time(NULL));

    printf("Generating %d random integers...\n", n);
    for (int i = 0; i < n; i++) {

        arr[i] = rand() % 10000; 
    }

    clock_t start, end;
    start = clock(); 
    
    quickSort(arr, 0, n - 1);
    
    end = clock();   

    double total_time = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("\nTotal execution time is: %f seconds\n", total_time);

    if (n <= 100) {
        printf("Sorted array: ");
        for (int i = 0; i < n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    } else {
        printf("Array is too large to display. Sorting complete.\n");
    }

    free(arr);
    return 0;
}