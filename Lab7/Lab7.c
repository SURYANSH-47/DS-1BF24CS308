#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;struct node* next;struct node* prev;
};
struct node* head=NULL;struct node* tail=NULL;
void creation(int m){
    if(m<=0){
        printf("Value cannot be less than zero equal to zero");
        return;
    }int l;
    for(int i=0;i<m;i++){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&l);
        newnode->data=l;newnode->prev=NULL;newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            tail->next=newnode;
            newnode->prev=tail;
        }
        tail=newnode;
    }

}
void insert_at_beegining(int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){head=tail=newnode;return;}
    newnode->next=head;
    head->prev=newnode;
    head=newnode;

}
void delete_by_value(int val){
    struct node* temp=head;
    while(temp!=NULL&&temp->data!=val){
        temp=temp->next;
    }
    if(temp==NULL){
        printf("VALUE NOT FOUND");
        return;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    free(temp);
}
void display(){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d\n",temp->data);
        temp=temp->next;
    }
}

int main(){
    int n,ch;int i=9;
    printf("1.Creation\n2.Insert at Begining\n3.Delete by value\n4.Display\n5.Exit\n");
    while(i>0){
        printf("\nEnter the operation: ");
        scanf("%d",&ch);
        switch(ch){
            case 1:
                printf("Enter the number of nodes to insert: ");
                scanf("%d",&n);
                creation(n);
                break;
            case 2:
                printf("Enter the value to insert: ");
                scanf("%d",&n);
                insert_at_beegining(n);
                break;
            case 3:
                printf("Enter th value to delete: ");
                scanf("%d",&n);
                delete_by_value(n);
                break;
            case 4:
                printf("The elements of list are: \n");
                display();
                break;
            case 5: exit(0);
                break;
            default:
                printf("Invalid input");

        }
    }
    return 0;
}