#include <stdio.h>
#define n 5
int stack[n];
int top = -1;
void push(int x)
{
    if (top == (n - 1))
    {
        printf("Stack overflow"); return;
    }
    else
    {
        top++;
        stack[top] = x;
    }
}
void pop()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("The deleted element is %d", stack[top]);
        top--;
    }
}
void peek()
{
    if (top == -1)
    {
        printf("Underflow");
    }
    else
    {
        printf("The top element is %d", stack[top]);
    }
}
int main()
{
    int v, w;
    printf("1.PUSH\n2.POP\n3.PEEK\n4.EXIT\n");
    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter the function to perfrom: ");
        scanf("%d", &w);
        switch (w)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &v);
            push(v);
            break;
        case 2:
            pop();
            break;
        case 3:
            peek();
            break;
        case 4:
            return 0;
            break;
        default:
            printf("Invalid input");
        }
    }
    return 0;
}