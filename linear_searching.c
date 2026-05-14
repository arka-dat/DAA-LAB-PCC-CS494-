#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void linear_search(int arr[], int n, int ele)
{
    int flag = 0;

    for(int i=0;i<n;i++)
    {
        if(arr[i]==ele)
        {
            printf("\nElement found at position %d", i+1);
            flag = 1;
            return;
        }
    }

    if(flag==0)
        printf("\nElement not found");
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

   // printf("\nArray values: ");

    for(int i=0;i<n;i++)
        arr[i] = i;

    printf("\n%d th position value is %d", n, arr[n-1]);

    printf("\nEnter the element you want to search: ");
    scanf("%d",&ele);

    clock_t start,end;
    double total_time;

    start = clock();
    linear_search(arr,n,ele);
    end = clock();

    total_time = (double)(end-start)/CLOCKS_PER_SEC;

    printf("\nTotal execution time = %f", total_time);

    return 0;
}