#include <stdio.h>
#include <stdbool.h>
#define MAX 100
bool isToeplitz(int matrix[MAX][MAX], int m, int n)
{
    for (int i = 0; i < m - 1; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (matrix[i][j] != matrix[i + 1][j + 1])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int m, n;
    int matrix[MAX][MAX];

    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    printf("Enter the matrix elements row-wise:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    if (isToeplitz(matrix, m, n))
    {
        printf("true\n");
    }
    else
    {
        printf("false\n");
    }

    return 0;
}
