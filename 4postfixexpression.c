#include<stdio.h>
#include<ctype.h>
#define MAX 100
int stack[MAX];
int top=-1;
void push(int item)
{
    if(top==MAX-1)
        printf("stack is full");
    else{
        top++;
        stack[top]=item;
    }
}
int pop()
{
    if(top==-1)
        printf("stack is empty");
    else{
        return stack[top--];
    }
}
int postfix(char *exp)
{
    char ch;
    int val1,val2,result;
    for(int i=0;exp[i]!='\0';i++)
    {
        ch=exp[i];
        if(isdigit(ch))
            push(ch-'0');//char to int
        else{
            val2=pop();
            val1=pop();
            switch (ch) {
                case '+':
                    result = val1 + val2;
                    break;
                case '-':
                    result = val1 - val2;
                    break;
                case '*':
                    result = val1 * val2;
                    break;
                case '/':
                    result = val1 / val2;
                    break;
                default:
                    printf("Invalid operator: %c\n", ch);
                    return 0;
            }
            push(result);
        }
    }
    return pop();
}

int main() {
    char exp[MAX];
    int result;

    printf("Enter the expression :: ");
    scanf("%s", exp);

    result = postfix(exp);

    printf("The result of expression %s  =  %d\n", exp, result);

    return 0;
}
