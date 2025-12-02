#include<stdio.h>
#define MAX 5

int stack [MAX];
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
void pop(int item)
{
    if(top==-1)
        printf("stack is empty");
    else
    {
        item=stack[top];
        printf("\ndelete item: %d",item);
        top-=1;
    }
}
void display()
{
    if(stack==-1)
        printf("stack is empty");
    else
    {
        printf("\nStack elements are: ");
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }
}
int main()
{
    push(10);
    push(20);
    push(30);
    display();
    pop(30);
    pop(10);
    display();
    return 0;
}
