#include <stdio.h>
#define MAX 100
void spiralOrder(int matrix[MAX][MAX], int m, int n)
{
    int top = 0, bottom = m - 1;
    int left = 0, right = n - 1;

    printf("Spiral order: [");

    int first = 1;

    while (top <= bottom && left <= right) {
        // Left to right
        for (int j = left; j <= right; j++) {
            if (!first) printf(", ");
            printf("%d", matrix[top][j]);
            first = 0;
        }
        top++;

        // Top to bottom
        for (int i = top; i <= bottom; i++) {
            if (!first) printf(", ");
            printf("%d", matrix[i][right]);
            first = 0;
        }
        right--;

        // Right to left
        if (top <= bottom) {
            for (int j = right; j >= left; j--) {
                if (!first) printf(", ");
                printf("%d", matrix[bottom][j]);
                first = 0;
            }
            bottom--;
        }

        // Bottom to top
        if (left <= right) {
            for (int i = bottom; i >= top; i--) {
                if (!first) printf(", ");
                printf("%d", matrix[i][left]);
                first = 0;
            }
            left++;
        }
    }
    printf("]\n");
}

int main() {
    int m, n;
    int matrix[MAX][MAX];

    printf("Enter number of rows (m): ");
    scanf("%d", &m);
    printf("Enter number of columns (n): ");
    scanf("%d", &n);

    printf("Enter the matrix elements row-wise:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    spiralOrder(matrix, m, n);

    return 0;
}
