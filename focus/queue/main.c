#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define max 10

int queue[max];
int front =-1;
int rear=-1;

bool is_Empty(){
    if(rear==-1){
        return true;
    }
    return false;
}

bool is_full(){
    if(rear==max-1){
        return true;
    }
    return false;
}

void enqueue(int data){
    if(is_full()){
        printf("Stack overflow!\n");
    }
    else{
            rear++;
        queue[rear]=data;
    }
}

void deque(){
    if(is_Empty()){
        printf("queue uunderflow\n");
    }
    else{
        front++;
        printf("the data deleted is %d\n",queue[front]);
    }
}
void display()
{
    if(is_Empty()){
        printf("No queue avaliable");
    }
    else
    {
        for(int i=front+1;i<=rear;i++){
            printf("%d->",queue[i]);
        }
        printf("\n");
    }

}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    display();
    deque();
    display();
}
