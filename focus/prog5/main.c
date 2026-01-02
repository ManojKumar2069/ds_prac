#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40
typedef struct Node
{
    char page_name[max];
    struct Node *link;
};

struct Node *create_l(char p[max])
{
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL)
    {
        printf("Memory is not allocated \n");
    }
    else
    {
        strcpy(nn->page_name,p);
        nn->link=NULL;
    }
    return nn;
};

struct Node *head=NULL;
struct Node *last=NULL;

struct Node *insert_r(char p[max])
{
    struct Node *newNode=create_l(p);
    if(head==NULL)
    {
        head=last=newNode;
    }
    else
    {
        last->link=newNode;
        last=newNode;
    }
    return newNode;
};

void display()
{
    if(head==NULL)
    {
        printf("LL does not exisit\n");
    }
    else
    {
        struct Node* temp=head;
        int i=0;
        while(temp!=NULL)
        {
            printf("page%d: %s ->",i,temp->page_name);
            temp=temp->link;
            i++;
        }
    }
};

struct Node *find_page(int x)
{
    if(head==NULL)
    {
        printf("LL is not avaliable");
    }
    else
    {
        struct Node *temp=head;
        int count=1;
        while(temp!=NULL&&count<x){
            temp=temp->link;
            count++;
        }
        if(temp!=NULL){
            printf("\n The element found at %d is %s \n",count,temp->page_name);
        }
        else{
            printf("invalid prevoius number of pages");
        }
    }
}

int main()
{
    insert_r("home");
    insert_r("contact");
    insert_r("about");
    insert_r("services");
    insert_r("feedback");
    display();
    find_page(2);
}
