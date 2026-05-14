#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void bubble_sort(int arr[], int n)
{
    int i, j, temp;

    for(i = 0; i < n-1; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nArray after sorting:\n");
    for(i = 0; i < n; i++)
        printf("%d\t", arr[i]);
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

    printf("\nOriginal array:\n");
    for(int j=0;j<n;j++)
        printf("%d\t",arr[j]);

    clock_t start,end;
    double total_time;

    start = clock();
    bubble_sort(arr,n);
    end = clock();

    total_time = (double)(end-start) / CLOCKS_PER_SEC;

    printf("\nTotal execution time is = %f", total_time);

    return 0;
}