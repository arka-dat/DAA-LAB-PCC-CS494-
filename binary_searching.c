#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int binary_search(int arr[], int n, int ele)
{
    int low = 0, high = n - 1;

    while(low <= high)
    {
        int mid = (low + high) / 2;

        if(arr[mid] == ele)  
            return mid;

        else if(arr[mid] < ele)
            low = mid + 1;

        else
            high = mid - 1;
    }

    return -1;  
}

int main()
{
    int n, ele;

    printf("\nEnter the total no of inputs in the array: ");
    scanf("%d",&n);

    int *arr = (int*) malloc(n * sizeof(int));

    if(arr == NULL)
    {
        printf("Memory allocation failed");
        return 1;
    }

    for(int i=0;i<n;i++)
        arr[i] = i;

    printf("\nLast element (index %d) = %d", n-1, arr[n-1]);

    printf("\nEnter the element you want to search: ");
    scanf("%d",&ele);

    clock_t start, end;
    double total_time;

    int pos;

    start = clock();

    for(int i = 0; i < 100000; i++)
    {
         pos = binary_search(arr, n, ele);
    }

    end = clock();

    total_time = (double)(end - start) / CLOCKS_PER_SEC;

    if(pos != -1)
        printf("\nElement found at position %d", pos + 1);
    else
        printf("\nElement not found");

    printf("\nTotal execution time = %.10f seconds", total_time);


    return 0;
}