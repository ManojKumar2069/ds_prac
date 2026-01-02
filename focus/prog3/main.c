#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40
typedef struct Node{
    char ind[max];
    struct Node* link;
};

struct Node *create(char ind[max]){
    struct Node *nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Memory is not allocated");
    }
    else{
        strcpy(nn->ind,ind);
        nn->link=NULL;
    }
    return nn;
};

struct Node* head=NULL;
struct Node* last=NULL;

struct Node *insert_front(char inda[max]){
    struct Node *newnode=create(inda);
    if(head==NULL){
        head=last=newnode;
    }
    else{
        newnode->link=head;
        head=newnode;
    }
    return head;
};

struct Node *delete_front(){
    if(head==NULL){
        printf("LL is not avaliable");
    }
    else{
        struct Node* temp=head;
        head=head->link;
        printf("\n deleted data is :%s \n",temp->ind);
        temp=NULL;
        free(temp);
    }
};

struct Node* delete_value(char ind[]){
    if(head==NULL){
        printf("LL no");
    }
    else{
        struct Node* temp=head;
        struct Node* prev=NULL;
        struct Node* next=NULL;
        while(temp!=NULL){
            if(strcmp(temp->ind,ind)==0){
                printf("found");
                next=temp->link;
                prev->link=next;
                temp=NULL;
                free(temp);
                return 0;
            }
            else{
                printf("Not found ");
                prev=temp->link;
                temp=temp->link->link;
            }
        }
    }
};

void display(){
    if(head==NULL){
        printf("LL NOT THERE");
    }
    else{
        struct Node *temp=head;
        while(temp!=NULL){
            printf("%s->",temp->ind);
            temp=temp->link;
        }
    }
}

int main()
{
    insert_front("biscuit");
    insert_front("milk");
    insert_front("teabag");
    insert_front("salt");
    insert_front("suger");
    printf("\n");
    display();
    delete_front();
    printf("\n");
        display();
    delete_value("milk");
    printf("\n");
    display();
    return 0;
}
