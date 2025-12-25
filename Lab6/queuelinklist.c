#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL;
struct node *rear = NULL;
void enqueue(int a)
{
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("MEMORT ALLOCATION FAILED");
        return;
    }
    newnode->data = a;
    newnode->next = NULL;
    if (front == NULL)
    {
        front = newnode;rear=newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}
void dequeue()
{
    if (front == NULL)
    {
        printf("Queue is empty\n");
        return;
    }
    else if (front->next == NULL)
    {
        printf("The deleted data is: %d \n", front->data);
        struct node *temp = front;
        front = rear = NULL;
        free(temp);
    }
    else
    {
        printf("The deleted data is: %d \n", front->data);
        struct node *temp = front;
        front = front->next;
        free(temp);
    }
}
void display()
{
    struct node *temp = front;
    printf("The elements of queue are: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
int main()
{
    int a, p;
    printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    while (1)
    {
        printf("Enter the operation: ");
        scanf("%d", &a);
        switch (a)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &p);
            enqueue(p);
            break;
        case 2:
            dequeue();
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