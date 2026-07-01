#include<stdio.h>

char stack[100];
int top = -1;

void push(char x)
{
    stack[++top] = x;
}

void pop()
{
    top--;
}

int main()
{
    char exp[100];
    int i;

    printf("Enter expression: ");
    scanf("%s", exp);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(exp[i] == '(')
        {
            push(exp[i]);
        }
        else if(exp[i] == ')')
        {
            if(top == -1)
            {
                printf("Not Balanced");
                return 0;
            }
            pop();
        }
    }

    if(top == -1)
        printf("Balanced");
    else
        printf("Not Balanced");

    return 0;
}