#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int pos,i;
struct node{
    int data;
    struct node *next;
};
struct  node *getnode();
void insertatbeg(int item);
void insertatend(int item);
void insertatpos(int item);
void deleteatbeg();
void deleteatend();
void deleteatpos();
void insert();
void deletenode();
void display();

struct node *head=NULL;
int count=0;
int main(){
    int choice;
    while(1)
    {
        printf("Choose the operation you want to perform:\n");
        printf("1.Insert\n2.Delete\n3.Display\n4.Exit\n");
        scanf("%d",&choice);
    
    switch(choice)
    {
        case 1:{
            insert();
            break;
        }
        case 2:{
            deletenode();
            break;
        }
        case 3:{
            display();
            break;
        }
        case 4:
        {
            exit(0);
            break;
        }
        default:
        printf("Invalid option...choose the correct operations\n");
    }
    }
    return 0;
}
struct node *getnode()
{
    struct node *newnode;
    newnode=(struct node *)malloc(sizeof(struct node));
    return newnode;
    }

void insertatbeg(int item)
{
    struct node *newnode;
    newnode=getnode();
    newnode->data=item;
    newnode->next=head;
    head=newnode;

}

void  insertatend(int item)
{
    struct node *newnode, *temp;
    newnode=getnode();
    newnode->data=item;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void insertatpos(int item){
    int pos,i=0,count=0;
    struct node *newnode,*temp;
    newnode=getnode();
    newnode->data=item;
    printf("Enter the position you want to insert:");
    scanf("%d",&pos);
    struct node *t;
    t=head;
    if(t==NULL){
        printf("List is empty.\n");
    }
    else{
        while(t!=NULL)
        {
         count=count+1; 
         t=t->next;  
        }
        printf("\n");
    }
    if(pos>count)
    {
        printf("invalid option since count=%d",count);
    }
    else{
        temp=head;
        while(i<pos-2)
        {
            temp=temp->next;
            i++;
        }
     newnode->next=temp->next;
    temp->next=newnode;
    }

}

void insert()
{
    int choice,data_add;
    printf("Choose the option:\n");
    printf("1.At the Beginning\n2.At the End\n3.At the specific position\n");
    scanf("%d",&choice);

    printf("Data to be inserted:");
    scanf("%d",&data_add);
    switch(choice){
        case 1:{
            insertatbeg(data_add);
            break;
        }
        case 2:{
            insertatend(data_add);
            break;
        }
        case 3:{
            insertatpos(data_add);
            break;
        }
        default:
        {
            printf("Invalid option\n");
        }
    }
}