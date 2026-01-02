#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define max 40
typedef struct Node{
    int usn;
    char name[max];
    long long number;
    struct Node* link;
};

struct Node* create(int u,char n[max],long long nu)
{
    struct Node* nn=(struct Node*)malloc(sizeof(struct Node));
    if(nn==NULL){
        printf("Memory cannot be allocated");
        return 0;
    }
    else{
        nn->usn=u;
        strcpy(nn->name,n);
        nn->number=nu;
        nn->link=NULL;
    }
    return nn;
};

struct Node *head=NULL;
struct Node *last=NULL;

struct Node* insert_front(int u,char n[max],long long nu){
    struct Node* newnode=create(u,n,nu);
    if(head==NULL){
        head=last=newnode;
    }
    else{
        newnode->link=head;
        head=newnode;
    }
    return head;
};

struct Node* delete_front(){
    if(head==NULL){
        printf("Linked list is empty");
    }
    else{
        struct Node* temp=NULL;
        temp=head;
        head=temp->link;
        printf("The deleted element data is \n");
        printf("usn:%d,name:%s,number:%lld",temp->usn,temp->name,temp->number);
        printf("\n");
        temp=NULL;
        free(temp);
    }
    return head;
};

void display(){
    if(head==NULL){
        printf("LL NOT THERE BRO\n");
    }
    else{
        struct Node* temp=head;
        while(temp!=NULL){
            printf("usn:%d,name:%s,number:%lld ->",temp->usn,temp->name,temp->number);
            printf("\n");
            temp=temp->link;
        }
    }
}

int main(){
    char n='a';
    char p='a';
    if(n==p){
        printf("yoo");
    }
    insert_front(101,"manoj",748374185);
    insert_front(102,"Akhi",7894511245);
    insert_front(103,"ashok",7418541236);
    insert_front(104,"rohit",9638540230);
    display();
    delete_front();
    printf("The remaing data is \n");
    display();
}
