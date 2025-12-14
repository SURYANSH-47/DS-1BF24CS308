#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;struct node* next;
};
struct node* head=NULL;
void creation(int m){
    if(m<=0){
        printf("Value cannot be less than zero equal to zero");
        return;
    }int l;
        struct node* temp=head;

    for(int i=0;i<m;i++){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter the data: ");
        scanf("%d",&l);
        newnode->data=l;newnode->next=NULL;
        if(head==NULL){
            head=newnode;
        }
        else{
            temp->next=newnode;
        }
        temp=newnode;
    }

}
void deletion_at_begining(){
    if(head==NULL){
        printf("EMPTY LIST");
        return;
    }
    struct node* temp=head;
    head=head->next;
    printf("The deleted element is %d",temp->data);
    free(temp);
}
void deletion_at_end(){
   
    if (head == NULL) {
        printf("EMPTY LIST\n");
        return;
    }
    struct node* temp = head;
    struct node* prev = NULL; 
    if (head->next == NULL) {
        printf("The deleted element is: %d\n", temp->data);
        free(head);
        head = NULL; 
        return;
    }
    while(temp->next != NULL){
        prev = temp; 
        temp = temp->next;
    }
    prev->next = NULL;  
    printf("The deleted element is: %d\n", temp->data);
    free(temp); 
}
void delete_by_position(int p){
    if(p<=0){
        printf("POSITION CANNOT BE ZERO OR LESS THAN ZERO");
        return;
    }
    struct node* temp=head;struct node* prev=NULL;
    for(int i=1;i<p;i++){
        prev=temp;
        temp=temp->next;
        
    }
    prev->next=temp->next;
    printf("The deleted element is %d",temp->data);
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
    printf("1.Creation\n2.Delete at Begining\n3.Delete at end\n4.Delete by position\n5.Display\n6.Exit\n");
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
                deletion_at_begining();
                break;
            case 3:
                deletion_at_end();
                break;
            case 4:
                printf("Enter the positon to delete: ");
                scanf("%d",&n);
                delete_by_position(n);
                break;
            case 5: 
                printf("ELEMENTS OF LINKED LIST ARE: \n");
                display();
                break;
            case 6:
                exit(0);
                break;
            default:
                printf("Invalid input");

        }
    }
    return 0;
}