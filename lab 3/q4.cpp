#include <stdio.h>
#include <stdlib.h>

void addMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] + B[i][j];
}

void subMatrix(int n, int A[n][n], int B[n][n], int C[n][n])
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            C[i][j] = A[i][j] - B[i][j];
}

void strassen(int n, int A[n][n], int B[n][n], int C[n][n])
{
    if (n == 1)
    {
        C[0][0] = A[0][0] * B[0][0];
        return;
    }

    int k = n / 2;

    int A11[k][k], A12[k][k], A21[k][k], A22[k][k];
    int B11[k][k], B12[k][k], B21[k][k], B22[k][k];

    int P1[k][k], P2[k][k], P3[k][k], P4[k][k];
    int P5[k][k], P6[k][k], P7[k][k];

    int T1[k][k], T2[k][k];

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            A11[i][j] = A[i][j];
            A12[i][j] = A[i][j + k];
            A21[i][j] = A[i + k][j];
            A22[i][j] = A[i + k][j + k];

            B11[i][j] = B[i][j];
            B12[i][j] = B[i][j + k];
            B21[i][j] = B[i + k][j];
            B22[i][j] = B[i + k][j + k];
        }
    }

    addMatrix(k, A11, A22, T1);
    addMatrix(k, B11, B22, T2);
    strassen(k, T1, T2, P1);

    addMatrix(k, A21, A22, T1);
    strassen(k, T1, B11, P2);

    subMatrix(k, B12, B22, T2);
    strassen(k, A11, T2, P3);

    subMatrix(k, B21, B11, T2);
    strassen(k, A22, T2, P4);

    addMatrix(k, A11, A12, T1);
    strassen(k, T1, B22, P5);

    subMatrix(k, A21, A11, T1);
    addMatrix(k, B11, B12, T2);
    strassen(k, T1, T2, P6);

    subMatrix(k, A12, A22, T1);
    addMatrix(k, B21, B22, T2);
    strassen(k, T1, T2, P7);

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            C[i][j] =
                P1[i][j] + P4[i][j] -
                P5[i][j] + P7[i][j];

            C[i][j + k] =
                P3[i][j] + P5[i][j];

            C[i + k][j] =
                P2[i][j] + P4[i][j];

            C[i + k][j + k] =
                P1[i][j] - P2[i][j] +
                P3[i][j] + P6[i][j];
        }
    }
}

int main()
{
    int n;

    printf("Enter matrix size: ");
    scanf("%d", &n);

    int A[n][n], B[n][n], C[n][n];

    printf("Enter Matrix A:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &A[i][j]);

    printf("Enter Matrix B:\n");

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &B[i][j]);

    strassen(n, A, B, C);

    printf("Result Matrix:\n");

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", C[i][j]);

        printf("\n");
    }

    return 0;
}
