#include <stdio.h>
#define n 5
int queue[n];
int front = -1;
int rear = -1;
void enueue(int x)
{
    if (rear == n - 1)
    {
        printf("Queue is full\n");
    }
    else if (rear == -1)
    {
        front++;
        rear++;
        queue[rear] = x;
    }
    else
    {
        rear++;
        queue[rear] = x;
    }
}
void dequeue()
{
    if (front == -1)
    {
        printf("Empty queue\n");
    }
    else if (front == rear)
    {
        int w = queue[front];
        front = rear = -1;
        printf("The deleted eleemnt is %d\n", w);
    }
    else
    {
        int q = queue[front];
        front++;
        printf("The deleted element is: %d\n", q);
    }
}
void display()
{
    printf("The elements of aueue are: ");
    for (int i = front; i <= rear; i++)
    {
        printf("%d\n", queue[i]);
    }
}
int main()
{
    int s, c;
    printf("1.ENQUEUE\n2.DEQUEUE\n3.DISPLAY\n4.EXIT\n");
    for (int i = 1; i > 0; i++)
    {
        printf("Enter the function to perfrom: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &s);
            enueue(s);
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
}