#include <stdio.h>

int main()
{
    int n, i, j, temp;
    int comparisons = 0;

    printf("Enter array size: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = 0; j < n - i - 1; j++)
        {
            comparisons++;

            if(arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printf("\nSorted Array:\n");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nComparisons = %d", comparisons);

    return 0;
}
