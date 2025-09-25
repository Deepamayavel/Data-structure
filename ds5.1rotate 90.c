#include <stdio.h>
#define MAX 100
void rotate(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = temp;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n / 2; j++)
        {
            int temp = matrix[i][j];
            matrix[i][j] = matrix[i][n - 1 - j];
            matrix[i][n - 1 - j] = temp;
        }
    }
}
void printMatrix(int matrix[MAX][MAX], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    int matrix[MAX][MAX];
    printf("Enter the size of the matrix (n x n): ");
    scanf("%d", &n);
    if (n <= 0 || n > MAX)
    {
        printf("Invalid matrix size. Must be between 1 and %d.\n", MAX);
        return 1;
    }
    printf("Enter the elements of the %d x %d matrix:\n", n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
    printf("\nOriginal Matrix:\n");
    printMatrix(matrix, n);
    rotate(matrix, n);
    printf("\nRotated Matrix (90 degrees clockwise):\n");
    printMatrix(matrix, n);
    return 0;
}
