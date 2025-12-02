#include<stdio.h>
#define MAX 50
int stack[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
        printf("stack is full");
    else
    {
        top+=1;
        stack[top]=item;
        printf("%d pushed into the stack.\n", item);
    }
}
int Max=-1;
int getMax()
{
    for(int i=top;i>=0;i--)
    {
        if(stack[i]>Max)
        {
            Max=stack[i];
        }
    }
    return Max;
}
int main()
{
    int n,i,value;
    printf("enter the number of elements:");
    scanf("%d",&n);
    printf("enter the %d elements:",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&value);
        push(value);
    }
   // push(12);
    //push(13);
    //push(2);
    //push(61);
    printf("the max no is: %d",getMax());
    return 0;
}
