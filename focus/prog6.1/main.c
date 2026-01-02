#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int coef;
    int pow;
    struct Node *link;
};

struct Node *create(int co,int po)
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Memory is not allocated");
    }
    else
    {
        nn->coef=co;
        nn->pow=po;
        nn->link=NULL;
    }
    return nn;
};

struct Node *insert_front(struct Node *head,int co,int po)
{
    struct Node *nn=create(co,po);
    if(head==NULL){
        head=nn;
    }
    else
    {
        nn->link=head;
        head=nn;
    }
    return head;
};

void display(struct Node* head)
{
    if(head==NULL)
    {
        printf("The lined list is not available");
    }
    else
    {
        struct Node *temp=head;
        while(temp!=NULL)
        {
            printf("%dX^%d ",temp->coef,temp->pow);
            temp=temp->link;
        }
        printf("\n");
    }
}


struct Node *poly_add(struct Node *p1,struct Node  *p2)
{
    struct Node *dummy=create(0,0);
    struct Node *poly=dummy;
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            poly->coef=p1->coef;
            poly->pow=p1->pow;
            p1=p1->link;
        }
        else if(p2->pow>p1->pow)
        {
            poly->coef=p2->coef;
            poly->pow=p2->pow;
            p2=p2->link;
        }
        else
        {
            poly->coef=(p1->coef+p2->coef);
            poly->pow=p1->pow;
            p1=p1->link;
            p2=p2->link;
        }
        poly->link=create(0,0);
        poly=poly->link;
    }
    while(p1!=NULL){
        poly->coef=p1->coef;
        poly->pow=p1->pow;
        p1=p1->link;
        poly->link=create(0,0);
        poly=poly->link;
    }
        while(p2!=NULL){
        poly->coef=p2->coef;
        poly->pow=p2->pow;
        p2=p2->link;
        poly->link=create(0,0);
        poly=poly->link;
    }
        struct Node *temp=dummy;
    while(temp->link!=NULL)
    {
        printf("%dX^%d ",temp->coef,temp->pow);
        temp=temp->link;
    }
};

int main()
{
    struct Node *p1=NULL;
    struct Node *p2=NULL;

     p1=insert_front(p1,5,0);
    p1=insert_front(p1,5,1);
    p1=insert_front(p1,4,2);
    p1=insert_front(p1,8,4);
    p1=insert_front(p1,6,5);

    p2=insert_front(p2,10,1);
    p2=insert_front(p2,12,2);
    p2=insert_front(p2,6,4);
    p2=insert_front(p2,3,5);

    display(p1);
    display(p2);

    poly_add(p1,p2);
}
