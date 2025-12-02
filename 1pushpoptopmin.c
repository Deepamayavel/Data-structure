#include<stdio.h>
#include<limits.h>
#define SIZE 50
int stack[SIZE];
int minstack[SIZE];
int top=-1 , mintop=-1;
void push(int item)
{
   stack[++top]=item;
   if(mintop==-1 || item<=minstack[mintop])
   {
       minstack[++mintop]=item;
       //printf("%d pushed into the stack.\n", item);
   }
}
void pop()
{
    if(top==-1)
    {
        printf("stack is empty");
        return;
    }
    if(stack[top]==minstack[mintop])
    {
        mintop--;
    }
    top--;
}
int topele()
{
    if(top==-1)
    {
        return -1;
    }
    return stack[top];
}
int getmin()
{
    if(mintop==-1)
    {
        return INT_MAX;
    }
    return minstack[mintop];
}
int main()
{
    push(-2);
    push(0);
    push(-3);
    printf("\nthe minimum elements is:%d\n",getmin());
    pop(0);
    printf("the top element is: %d",topele());
    printf("\nthe minimum element now is : %d",getmin());
    return 0;
}
