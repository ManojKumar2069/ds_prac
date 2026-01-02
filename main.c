#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#define max 10
char stack[max];
char postfix[max];
int top=-1;

bool is_Empty(){
    if(top==-1){
        return true;
    }
    return false;
}

bool if_full()
{
    if(top==max-1){
        return true;
    }
    return false;
}

void push(char data){
    if(if_full()){
        printf("Stack overflow");
    }
    else
    {
        top++;
        stack[top]=data;
    }
}

char pop(){
    if(is_Empty()){
        printf("Stack underflow");
    }
    else{
            return stack[top--];
    }
}
void diaplay()
{
    if(is_Empty()){
        printf("stack is empty");
    }
    else{
            printf("The elements in the stack are \n");
        for(int i=-1;i<=top-1;i++){
            printf("%d \n",stack[i]);
        }
    }
}

int precedency(char c)
{
    if(c=='^'){
        return 3;
    }
    else if(c=='/'||c=='*'){
        return 2;
    }
    else if(c=='+'||c=='-'){
        return 1;
    }
    else{
        return 0;
    }
}

void infix_to_post(char infix[]){
    int i,j=0;
    char ch;
    push('#');
    for(i=0;infix[i]!='\0';i++){
            ch=infix[i];
        if(isalnum(ch)){
            postfix[j++]=ch;
        }
        else if(ch=='('){
                    push(ch);
        }
        else if(ch==')'){
            while(!is_Empty()&&top!='('){
                    postfix[j++]=pop();
                  }
                  pop();
        }
        else{
            while(!is_Empty()&&precedency(top)>=precedency(ch)){
                postfix[j++]=pop();
            }
            push(ch);
        }
    }
    while(!is_Empty()&&stack[top]!='#'){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("The postfix expression is %s",postfix);
}
int main()
{
    char infix[max];
    scanf("%s",infix);
    infix_to_post(infix);
}


