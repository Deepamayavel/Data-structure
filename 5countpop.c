#include <stdio.h>
#define MAX 5
int stack[MAX];
int top=-1;
void push(int value)
{
    if(top==MAX-1)
    {
        printf("Stack Overflow");
        return;
    }
    stack[++top]=value;
}
int main()
{
    int size,arr[10],value;
    int popped[100] = {0};
    int i, j, top = 0;
    printf("Enter the size:");
    scanf("%d",&size);
    printf("Enter the elements:");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the elements:");
    for(i=0;i<size;i++)
    {
         scanf("%d",&value);
         push(value);
    }
    for (i = 0; i < size; i++) {
        int target = arr[i];
        int count = 0;
        if (popped[target]) {
            printf("0");
            continue;
        }
        while (top < size) {
            int current = stack[top];
            popped[current] = 1;
            count++;
            top++;
            if (current == target)
                break;
        }
        printf("%d ", count);
    }
    return 0;
}
