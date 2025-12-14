#include<stdio.h>
#define n 5
int queue[n];
int front=-1;
int rear=-1;
void enqueue(int x){
    if(((rear+1)%n)==front){
        printf("Queue is full\n");
    }
    else if(front==-1&&rear==-1){
        front++;rear++;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%n;
        queue[rear]=x;
    }
}
void dequeue(){
    if(rear==-1&&front==-1){
        printf("Queue is empty\n");
    }
    else if(front==rear){
        int y=queue[front];
        printf("The deleted element is: %d\n",y);
        front=rear=-1;
    }
    else{
        int y=queue[front];
        front=(front+1)%n;
        printf("The deleted element is: %d",y);

    }
}
void display()
{
    printf("The elements of queue are: ");
    for(int i = front; i != (rear+1)%n;i=(i+1)%n)
    {
        printf("%d\n", queue[i]);
    }
}
int main()
{
    int s, c;
    printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter the function to perfrom: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the element to insert: ");
            scanf("%d", &s);
            enqueue(s);
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