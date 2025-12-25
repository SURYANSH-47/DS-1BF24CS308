#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL;
struct node *head2 = NULL;
void creation1(int n)
{
    int a;
    if (n < 0)
    {
        printf("Number should be greater than 1\n");
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
            if (head1 == NULL)
            {
                head1 = newnode;
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;
        }
    }
}
void creation2(int n)
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
            if (head2 == NULL)
            {
                head2 = newnode;
            }
            else
            {
                temp->next = newnode;
            }
            temp = newnode;
        }
    }
}
void display()
{
    printf("DISPLAY FUNCTION CALLED\n");
    struct node *temp;
    temp = head1;
    printf("The elements of linked list are: \n");
    while (temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void concatenation(){
    if(head1==NULL){
        head1=head2;return;
    }
    struct node* temp=head1;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=head2;
}
void sort(){
    if(head1==NULL){
        printf("LIST IS EMPTY\n");return;
    }
    struct node *i,*j;
    int temp;
    for(i=head1;i->next!=NULL;i=i->next){
        for(j=i->next;j!=NULL;j=j->next){
            if(i->data>j->data){
                temp=i->data;
                i->data=j->data;
                j->data=temp;
            }
        }
    }

}
void reverse(){
    struct node* prev=NULL;
    struct node* current=head1;
    struct node* next;
    while(current!=NULL){
        next=current->next;
        current->next=prev;prev=current;
        current=next;
    }
    head1=prev;
}
int main()
{
    int a, p, c;
    printf("1.Creation of list 1\n2.Cfreation of list 2\n3.Concatenation\n4.Sort\n5.Reverse\n6.Display\n7.Exit");
    for (int i = 1; i > 0; i++)
    {
        printf("\nEnter the operation: ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("CREATION 1 CALLED\n");

            printf("Enter the number of elements to insert: ");
            scanf("%d", &a);
            creation1(a);
            break;
         case 2:
            printf("CREATION 2 CALLED\n");

            printf("Enter the number of elements to insert: ");
            scanf("%d", &a);
            creation2(a);
            break;
        case 3:
            printf("CONVATENATION CALLED");
            concatenation();
            break;
        case 4:
            printf("SORT CALLED");
            sort();
            break;
        case 5:
            printf("REVERSE CALLED");
            reverse();
            break;
        case 6:
            display();
            break;
        case 7:
            return 0;break;
        default:
            printf("INVALID INPUT\n");
            break;
        }}
    return 0;
}
