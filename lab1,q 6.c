#include <stdio.h>

int main()
{
    int n, i, j;
    int duplicate = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements:\n");

    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    for(i = 0; i < n - 1; i++)
    {
        for(j = i + 1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                duplicate = 1;
                printf("Duplicate Element: %d\n", arr[i]);
            }
        }
    }

    if(!duplicate)
        printf("No duplicate elements found.\n");

    return 0;
}
