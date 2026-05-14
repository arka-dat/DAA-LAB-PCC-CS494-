#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// Merge function
void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for(j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0; j = 0; k = l;

    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    while(j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Merge Sort function
void merge_sort(int arr[], int l, int r)
{
    if(l < r)
    {
        int m = (l + r) / 2;

        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

int main()
{
    int n;
    printf("\nEnter the total no of inputs in the array: ");
    scanf("%d",&n);

    int arr[n];

    printf("\nThe value within the array using rand function:\n");
    srand(time(0));

    for(int i=0;i<n;i++)
        arr[i]=rand()%20000;

    // Print original array
    printf("\nOriginal array:\n");
    for(int j=0;j<n;j++)
        printf("%d\t",arr[j]);

    clock_t start,end;
    double total_time;

    start = clock();
    merge_sort(arr, 0, n-1);
    end = clock();

    printf("\nArray after sorting:\n");
    for(int i=0;i<n;i++)
        printf("%d\t", arr[i]);

    total_time = (double)(end-start) / CLOCKS_PER_SEC;

    printf("\nTotal execution time is = %f", total_time);

    return 0;
}