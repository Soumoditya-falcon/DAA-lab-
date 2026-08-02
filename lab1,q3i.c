#include<stdio.h>

int main()
{
    int n, i, j, temp, swapped;
    int comparisons = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        swapped = 0;

        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }

        if(swapped == 0)
            break;
    }

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons = %d", comparisons);

    return 0;
}
