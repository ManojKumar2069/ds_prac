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
struct Playlist *create_p(char p)
{
    struct Playlist *nn=(struct Playlist*)malloc(sizeof(struct Playlist));
    if(nn==NULL)
    {
        printf("Memory not allocated");
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
        printf("Memory cannot be allocated");
    }
    else
    {
        strcpy(nn->s_name,s);
        nn->left=NULL;
        nn->right=NULL;
    }
    return nn;
};
struct Playlist *p_head=NULL;
struct Playlist *p_last=NULL;

struct Song *s_head=NULL;
struct Song *s_last=NULL;
struct Playlist *insert_p(char p)
{
    struct Playlist *nn=create_p(p);
    if(p_head==NULL)
    {
        p_head=nn;
        p_last=p_head;
    }
    else{
        p_last->right=nn;
        nn->left=p_last;
        p_last=nn;
    }
    return nn;
};

struct Song *insert_s(struct Playlist *p,char s[max])
{
    struct Song *nn=create_s(s);
    if(p->song_head==NULL){
        p->song_head=nn;
    }
    else
    {
        nn->right=p->song_head;
        p->song_head->left=nn;
        p->song_head=nn;
    }
    return p->song_head;
};


void display(struct Playlist *head)
{
    if(head==NULL)
    {
        printf("No songs in playlist");
    }
    else{
                        struct Song *s=head->song_head;
        printf("The songs in playlist %c\n",head->p_name);
        while(s!=NULL){
        printf("The songs are %s\n",s->s_name);
        s=s->right;
        }

    }
}


int main()
{
    struct Playlist *p1=NULL;
    struct Playlist *p2=NULL;
    p1=insert_p('a');
    insert_s(p1,"motivation1");
    insert_s(p1,"motivation2");

    p2=insert_p('b');
    insert_s(p2,"Sad songs");
    insert_s(p2,"Sad songs");

    display(p1);
    display(p2);
}
