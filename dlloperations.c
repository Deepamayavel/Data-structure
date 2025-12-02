#include <stdio.h>
#include <stdlib.h>
struct node {
    int data;
    struct node *next;
    struct node *prev;
    struct node *node;
} *head = NULL;
struct node*node;
struct node* getnode(int data) {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    if (newnode == NULL) {
        return NULL;
    }
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}
int insertatbegin()
{
    int elt;
    printf("enter val to insert:");
    scanf("%d",&elt);
    struct node* newnode = getnode(node);
   // newnode=getnode(*node);
    newnode->data=elt;
    newnode->prev=NULL;
    if(head==NULL)
    {
        newnode->next=NULL;
        head=newnode;
        return head;
    }
    newnode->next=head;
    head->prev=newnode;
    head=newnode;
    return head;
    printf("%d is inserted at begin.",elt);
}
int insertatpos()
{
    int elt,pos;
    printf("enter elt,pos: ");
    scanf("%d %d",&elt,&pos);
    if(head==NULL)
    {
        printf("error,empty list");
        return;
    }
    struct node*temp=head;
    int i=1;
    while(i<pos-1 && temp!=NULL)
    {
        temp=temp->next;
        i=i+1;
    }
    if(temp!=NULL)
    {
        struct node*newnode=getnode(node);
        newnode->data=elt;
        newnode->next=temp->next;
        newnode->prev=temp;
        if(temp->next!=NULL)
        {
            temp->next->prev=newnode;
        temp->next=newnode;
        }
        else{
            printf("error,invalid pos");
        }
        return head;
    }
}
int insertatend()
{
    int elt;
    printf("enter no to insert:");
    scanf("%d",&elt);
    struct node*newnode=getnode(node);
    newnode->data=elt;
    newnode->next=NULL;
    if(head==NULL)
    {
        newnode->node=NULL;
        head=newnode;
        return head;
    }
    struct node*temp=head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=newnode;
    newnode->prev=temp;
    return head;
}
void deleteFront() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct node* temp = head;
    if (head->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }

    head = head->next;
    head->prev = NULL;
    free(temp);
}
void deleteEnd() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct node* temp = head;
    if (temp->next == NULL) {
        head = NULL;
        free(temp);
        return;
    }
    while (temp->next != NULL)
        temp = temp->next;

    temp->prev->next = NULL;
    free(temp);
}
void deleteAtPos()
{
    int pos;
    printf("enter the pos to delete");
    scanf("%d",&pos);
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (pos <= 0) {
        printf("Invalid position\n");
        return;
    }
    struct node *temp = head;
    if (pos == 1) {
        if (head->next == NULL) {
            free(head);
            head = NULL;
            return;
        }

        head = head->next;
        head->prev = NULL;
        free(temp);
        return;
    }
    int i = 1;
    while (i < pos && temp != NULL) {
        temp = temp->next;
        i++;
    }
    if (temp == NULL) {
        printf("Position out of range\n");
        return;
    }
    if (temp->next == NULL) {
        temp->prev->next = NULL;
        free(temp);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
}

int deletep()
{
    struct node *p;
    printf("enter the pointer to delete:");
    scanf("%d",&p);
    if(head==NULL)
        printf("empty list");
    return NULL;
    if(p==head)
    {
        head=head->next;
        head->prev=NULL;
        free(p);
        return head;
    }
    p->prev->next=p->next;
    p->next->prev=p->prev;
    free(p);
    return head;
}
void display() {
    struct node* temp = head;
    printf("List: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    printf("\nMENU\n1.insert at begin\n2.insert at given pos\n3.insert at end\n4.delete at front\n5.delete at end\n6.delete at given pos");
    int choice;
    char ch;
    do{
        printf("\nenter the choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:insertatbegin();
            display();
            break;
            case 2:insertatpos();
            display();
            break;
            case 3:insertatend();
            display();
            break;
            case 4:deleteFront();
            display();
            break;
            case 5:deleteEnd();
            display();
            break;
            case 6:deleteAtPos();
            display();
            break;

        }
        printf("do you want to continue say 'y' or 'n' ");
        scanf(" %c",&ch);
    }while(ch=='y'||ch=='Y');
    return 0;
}
