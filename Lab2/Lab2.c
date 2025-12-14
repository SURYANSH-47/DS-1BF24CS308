#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define n 11
char stack[n];
int top = -1;
void push(char c)
{
    if (top == (n - 1))
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = c;
}
char pop()
{
    if (top == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    return stack[top--];
}
char peek()
{
    if (top == -1)
    {
        printf("Stack underflow");
        return -1;
    }
    return stack[top];
}
int associativity(char c)
{
    if (c == '^')
    {
        return 1;
    }
    return 0;
}
int precedence(char c)
{
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    case '(':
        return 0;
    }
    return -1;
}
void postfixtoprefix(char prefix[n], char postfix[n])
{
    int i;
    int k = 0;
    char c;

    for (i = 0; i < strlen(prefix); i++)
    {
        c = prefix[i];
        if (isalnum(c))
        {
            postfix[k++] = c;
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (peek() != '(')
            {
                postfix[k++] = pop();
            }
            pop();
        }
        else
        {
            while (top != -1 && ((precedence(peek()) > precedence(c)) || ((precedence(peek()) == precedence(c)) && associativity(c) == 0)))
            {
                postfix[k++] = pop();
            }
            push(c);
        }
    }
    while (top != -1)
    {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
}
int main()
{
    char infix[n];
    printf("Enter the infix equation: ");
    gets(infix);
    char postfix[n];
    postfixtoprefix(infix, postfix);
    printf("The postfix expression is: ");
    puts(postfix);
    return 0;
}