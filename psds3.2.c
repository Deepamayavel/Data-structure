#include<stdio.h>
int main()
{
    int m,n,i,j;
    printf("enter no.of rows:");
    scanf("%d",&m);
    printf("enter no.of columns:");
    scanf("%d",&n);
    int matrix[m][n];
    printf("enter the elements of matrix:\n");
    for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&matrix[i][j]);
            }
        }
int top_left=matrix[0][0];
int top_right=matrix[0][n-1];
int bottom_left=matrix[m-1][0];
int bottom_right=matrix[m-1][n-1];
int sum=top_left+top_right+bottom_left+bottom_right;

printf("corner elements:%d %d %d %d\n",top_left,top_right,bottom_left,bottom_right);
printf("corner_sum=%d\n",sum);
return 0;
}
