#include<stdio.h>
int main()
{
    int m,n;
    int i,j,count=0;
    printf("enter no.of rows:");
    scanf("%d",&m);
    printf("enter no.of columns:");
    scanf("%d",&n);
    int matrix[m][n];
    printf("enter elements of matrix:\n");
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&matrix[i][j]);
                if(matrix[i][j]==0)
                    {
                        count++;
                    }
            }
        }
        if(count>(m*n)/2)
            {
                printf("the matrix is a sparse matrix.\n");
            }
        else
            {
                printf("the matrix is not a sparse matrix.\n");
            }

        return 0;
}
