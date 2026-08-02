#include <stdio.h>

int main()
{
    int n, i;
    int low, high, mid;

    printf("Enter size of array: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array (0s followed by 1s):\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(arr[mid] == 0)
            low = mid + 1;
        else
            high = mid - 1;
    }

    if(low == n)
        printf("No 1 found.\n");
    else
        printf("Partition point is at index %d\n", low);

    return 0;
}
