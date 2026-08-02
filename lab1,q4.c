#include<stdio.h>

int moves = 0;

void tower(int n, char source, char auxiliary, char destination)
{
    if(n == 1)
    {
        printf("Move Disk 1 from %c to %c\n", source, destination);
        moves++;
        return;
    }

    tower(n - 1, source, destination, auxiliary);

    printf("Move Disk %d from %c to %c\n", n, source, destination);
    moves++;

    tower(n - 1, auxiliary, source, destination);
}

int main()
{
    int n;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    tower(n, 'A', 'B', 'C');

    printf("\nTotal Moves = %d\n", moves);

    return 0;
}
