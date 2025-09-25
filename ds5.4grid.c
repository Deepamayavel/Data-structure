#include <stdio.h>
#define MAX 100
int countNegatives(int grid[MAX][MAX], int m, int n) {
    int row = m - 1;
    int col = 0;
    int count = 0;

    while (row >= 0 && col < n)
    {
        if (grid[row][col] < 0)
        {
            count += (n - col);
            row--;  // Move up
        } else
        {
            col++;  // Move right
        }
    }
    return count;
}

int main() {
    int m, n;
    int grid[MAX][MAX];

    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    printf("Enter the matrix elements row-wise:\n");
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }

    int result = countNegatives(grid, m, n);
    printf("Number of negative numbers: %d\n", result);
    return 0;
}
