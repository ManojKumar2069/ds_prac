#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    int pow;
    struct Node *link;
};

struct Node *create_n(int d,int p)
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Memory is not allocated");
    }
    else{
        nn->data=d;
        nn->pow=p;
        nn->link=NULL;
    }
    return nn;
};


struct Node *insert_front(struct Node *head,int d,int p)
{
    struct Node *newNode=create_n(d,p);
    if(head==NULL)
    {
        head=newNode;
    }
    else
    {
        newNode->link=head;
        head=newNode;
    }
    return head;
};

void display(struct Node *head_t)
{
    if(head_t==NULL)
    {
        printf("LL is not avaliable");
    }
    else{
        struct Node *temp=head_t;
        while(temp!=NULL)
        {
            printf("%dx^%d ",temp->data,temp->pow);
            temp=temp->link;
        }
        printf("\n");
    }
};

struct Node *poly_add(struct Node *p1,struct Node *p2)
{
    struct Node *head=create_n(0,0);
    struct Node *poly=head;
    while(p1!=NULL && p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            poly->pow=p1->pow;
            poly->data=p1->data;
            p1=p1->link;
        }
        else if(p2->pow>p1->pow)
        {
            poly->pow=p2->pow;
            poly->data=p2->data;
            p2=p2->link;
        }
        else
        {
            poly->data=p1->data+p2->data;
            poly->pow=p1->pow;
            p1=p1->link;
            p2=p2->link;
        }
        poly->link=create_n(0,0);
        poly=poly->link;
    }
    struct Node *temp=head;
        while(temp->link!=NULL)
        {
            printf("%dx^%d ",temp->data,temp->pow);
            temp=temp->link;
        }
        printf("\n");
};

int main()
{
    struct Node *p1=NULL;
    struct Node *p2=NULL;
    p1=insert_front(p1,2,1);
    p1=insert_front(p1,3,2);
    p1=insert_front(p1,4,2);
    p1=insert_front(p1,5,3);

    p2=insert_front(p2,6,1);
    p2=insert_front(p2,8,2);
    p2=insert_front(p2,6,2);
    p2=insert_front(p2,8,3);
    display(p1);
    display(p2);

    poly_add(p1,p2);
}
