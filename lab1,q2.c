#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int tosses, i;
    int fairHead = 0, biasedHead = 0;
    double probability;

    printf("Enter number of tosses: ");
    scanf("%d", &tosses);

    printf("Enter probability of HEAD for biased coin (0 to 1): ");
    scanf("%lf", &probability);

    srand(time(NULL));

    // Fair Coin
    for(i = 0; i < tosses; i++)
    {
        if(rand() % 2 == 0)
            fairHead++;
    }

    // Biased Coin
    for(i = 0; i < tosses; i++)
    {
        double r = (double)rand() / RAND_MAX;
        if(r < probability)
            biasedHead++;
    }

    printf("\nFair Coin:\n");
    printf("Heads = %d\n", fairHead);
    printf("Probability = %.4f\n", (double)fairHead / tosses);

    printf("\nBiased Coin:\n");
    printf("Heads = %d\n", biasedHead);
    printf("Probability = %.4f\n", (double)biasedHead / tosses);

    return 0;
}
