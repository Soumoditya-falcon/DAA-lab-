#include <stdio.h>

int findDefective(double weight[], int left, int right, int good)
{
    if (left == right)
    {
        if (weight[left] < weight[good])
            return left;
        else
            return -1;
    }

    int n = right - left + 1;

    int mid = (left + right) / 2;

    int leftStart = left;
    int leftEnd = mid;

    int rightStart = mid + 1;
    int rightEnd = right;

    int leftCount = leftEnd - leftStart + 1;
    int rightCount = rightEnd - rightStart + 1;

    double leftWeight = 0;
    double rightWeight = 0;

    for (int i = leftStart; i <= leftEnd; i++)
        leftWeight += weight[i];

    for (int i = rightStart; i <= rightEnd; i++)
        rightWeight += weight[i];

    if (leftWeight < rightWeight)
    {
        return findDefective(weight, leftStart, leftEnd, good);
    }
    else if (rightWeight < leftWeight)
    {
        return findDefective(weight, rightStart, rightEnd, good);
    }
    else
    {
        if (leftCount == rightCount)
            return -1;

        int candidate = right;

        if (weight[candidate] < weight[good])
            return candidate;
        else
            return -1;
    }
}

int main()
{
    int n;

    printf("Enter number of coins: ");
    scanf("%d", &n);

    double weight[n];

    printf("Enter weights of coins:\n");

    for (int i = 0; i < n; i++)
        scanf("%lf", &weight[i]);

    int defective = findDefective(weight, 0, n - 1, 0);

    if (defective == -1)
        printf("No defective coin found.\n");
    else
        printf("Defective coin = %d\n", defective + 1);

    return 0;
}
