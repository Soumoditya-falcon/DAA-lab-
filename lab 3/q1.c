#include <stdio.h>

int binarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;
    int comparisons = 0;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        comparisons++;

        if (a[mid] == x)
        {
            printf("Binary Search Comparisons = %d\n", comparisons);
            return mid;
        }
        else if (x < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    printf("Binary Search Comparisons = %d\n", comparisons);
    return -1;
}

int ternarySearch(int a[], int n, int x)
{
    int low = 0, high = n - 1;
    int comparisons = 0;

    while (low <= high)
    {
        int mid1 = low + (high - low) / 3;
        int mid2 = high - (high - low) / 3;

        comparisons++;

        if (a[mid1] == x)
        {
            printf("Ternary Search Comparisons = %d\n", comparisons);
            return mid1;
        }

        comparisons++;

        if (a[mid2] == x)
        {
            printf("Ternary Search Comparisons = %d\n", comparisons);
            return mid2;
        }

        if (x < a[mid1])
        {
            high = mid1 - 1;
        }
        else if (x > a[mid2])
        {
            low = mid2 + 1;
        }
        else
        {
            low = mid1 + 1;
            high = mid2 - 1;
        }
    }

    printf("Ternary Search Comparisons = %d\n", comparisons);
    return -1;
}

int main()
{
    int n, x, i;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted array:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &x);

    int b = binarySearch(a, n, x);
    int t = ternarySearch(a, n, x);

    if (b != -1)
        printf("Element found by Binary Search at index %d\n", b);
    else
        printf("Element not found by Binary Search\n");

    if (t != -1)
        printf("Element found by Ternary Search at index %d\n", t);
    else
        printf("Element not found by Ternary Search\n");

    return 0;
}
