#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define max 40

typedef struct Playlist
{
    char p_name;
    struct Song *song_head;
    struct Playlist *left;
    struct Playlist *right;
};

struct Song
{
    char s_name[max];
    struct Song *left;
    struct Song *right;
};
struct Playlist *p_head=NULL;
struct Playlist *p_last=NULL;
struct Playlist *create_p(char p)
{
    struct Playlist *nn=(struct Playlist*)malloc(sizeof(struct Playlist));
    if(nn==NULL)
    {
        printf("Memeroy not allocated");
    }
    else
    {
        nn->p_name=p;
        nn->left=NULL;
        nn->right=NULL;
        nn->song_head=NULL;
    }
    return nn;
};

struct Song *create_s(char s[max])
{
    struct Song *nn=(struct Song *)malloc(sizeof(struct Song));
    if(nn==NULL)
    {
        printf("Memory not allocated");
    }
    else
    {
        strcpy(nn->s_name,s);
        nn->left=NULL;
        nn->right=NULL;
    }
    return nn;
};

struct Playlist *insert_p(char p)
{
    struct Playlist *nn=create_p(p);
    if(p_head==NULL)
    {
        p_head=nn;
        p_last=p_head;
    }
    else
    {
        nn->right=p_head;
        p_head->left=nn;
        p_head=nn;
    }
    return nn;
};

struct Song *insert_s(struct Playlist *p,char s[max])
{
    struct Song *nn=create_s(s);
    if(p->song_head==NULL)
    {
        p->song_head=nn;
    }
    else
    {
        nn->right=p->song_head;
        p->song_head->left=nn;
        p->song_head=nn;
    }
    return nn;
};

void display(struct Playlist *p)
{
    if(p==NULL){
        printf("No playlist");
    }
    else
    {
        printf("Playist %c\n",p->p_name);
        struct Song *s=p->song_head;
        while(s!=NULL){
            printf("%s\n",s->s_name);
            s=s->right;
        }
    }
}

void delete_s_at_pos(struct Playlist *p,int pos){
    struct Song *s=p->song_head;
    if(s==NULL)
    {
        printf("No songs avaliable");
    }
    else
    {
        struct Song *prev=NULL;
        struct Song *next=NULL;
        int i=1;
        while(s!=NULL && i<pos){
            prev=s;
            s=s->right;
            i++;
        }
        if(s==NULL){
            printf("Postition out of bound");
        }
        else{
            next=s->right;
            struct Song *temp=s;
            printf("The deleted data is %s\n",temp->s_name);
            prev->right=next;
            next->left=prev;
            temp=NULL;
            free(temp);
        }
    }

};

int main()
{
    struct Playlist *p1=NULL;
    struct Playlist *p2=NULL;

    p1=insert_p('A');
    insert_s(p1,"Motivation song 4");
    insert_s(p1,"Motivation song 3");
    insert_s(p1,"Motivation song 2");
    insert_s(p1,"Motivation song 1");

    p2=insert_p('B');
    insert_s(p2,"Sad song 1");
    insert_s(p2,"Sad song 2");

    display(p1);
    display(p2);

    delete_s_at_pos(p1,2);
    display(p1);
    delete_s_at_pos(p1,5);
}
