#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void push(int a)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    if (top == NULL)
    {
        top = newnode;
    }
    else
    {
        newnode->next = top;
        top = newnode;
    }
}
void pop()
{
    if (top == NULL)
    {
        printf("Stack underflow\n");
        return;
    }
    else if (top->next == NULL)
    {
        printf("The deleted data is: %d\n", top->data);
        struct node *temp = top;
        top = NULL;
        free(temp);
    }
    else
    {
        struct node *temp = top;
        printf("The deleted data is: %d\n", top->data);

        top = top->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = top;
    printf("The elements of stack are: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int a, p;
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.EXIT\n");
    while (1)
    {
        printf("Enter the operation: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element ot push: ");
            scanf("%d", &p);
            push(p);
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            return 0;
        }
    }
    return 0;
}