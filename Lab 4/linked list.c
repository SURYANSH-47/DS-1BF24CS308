#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL;
void creation(int n)
{
    int a;
    if (n < 0)
    {
        printf("Number shoulb be greater than 1\n");
    }
    else
    {
        struct node *newnode, *temp;

        for (int i = 0; i < n; i++)
        {
            newnode = (struct node *)malloc(sizeof(struct node));
            printf("Enter the data: ");
            scanf("%d", &a);
            newnode->data = a;
            newnode->next = NULL;
            if (head == NULL)
            {
                head = newnode;
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;
        }
    }
}
void insert_at_begining(int a)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }
    else
    {
        newnode->next = head;
        head = newnode;
    }
}
void insert_at_end(int a)
{
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    newnode->next = NULL;
    if (head == NULL)
    {
        head = newnode;
    }

    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void insert_at_position(int a, int p)
{
    struct node *newnode, *temp;
    temp = head;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = a;
    for (int i = 1; i < p - 1; i++)
    {
        temp = temp->next;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void display()
{
    printf("DISPLAY FUNCTION CALLED\n");
    struct node *temp;
    temp = head;
    printf("The elements of linked list are: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int a, p, c;
    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter the operation: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("CREATION CALLED\n");

            printf("Enter the number of elements to insert: ");
            scanf("%d", &a);
            creation(a);
            break;
        case 2:
            printf("INSERT AT BEGINING CALLED\n");

            printf("Enter the element to insert: ");
            scanf("%d", &a);
            insert_at_begining(a);
            break;
        case 3:
            printf("INSERT AT END CALLED\n");

            printf("Enter the element to insert: ");
            scanf("%d", &a);
            insert_at_end(a);
            break;
        case 4:
            printf("INSERT AT ANY POSITION CALLED\n");

            printf("Enter the position to insert: ");
            scanf("%d", &p);
            printf("Enter the element to insert: ");
            scanf("%d", &a);
            insert_at_position(a, p);
            break;
        case 5:
            display();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid input\n");
            break;
        }
    }

    return 0;
}
