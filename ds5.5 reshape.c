#include <stdio.h>

#define MAX 100

void printMatrix(int matrix[MAX][MAX], int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int m, n, r, c;
    int mat[MAX][MAX];
    int reshaped[MAX][MAX];

    printf("Enter original matrix size (m n): ");
    scanf("%d %d", &m, &n);

    printf("Enter the matrix elements row-wise:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }

    printf("Enter reshape size (r c): ");
    scanf("%d %d", &r, &c);

    if (m * n != r * c)
    {
        printf("Reshape not possible. Original matrix:\n");
        printMatrix(mat, m, n);
        return 0;
    }

    int idx = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int row = idx / c;
            int col = idx % c;
            reshaped[row][col] = mat[i][j];
            idx++;
        }
    }

    printf("Reshaped matrix:\n");
    printMatrix(reshaped, r, c);

    return 0;
}
