#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define max 10

int stack[max];
int temp[max];
int top = -1;
int ttop = -1;

bool is_Empty(int t) {
    return t == -1;
}

bool is_Full(int t) {
    return t == max - 1;
}

void push(int s[], int *t, int x) {
    if (is_Full(*t)) {
        printf("Stack Overflow\n");
        return;
    }
    s[++(*t)] = x;
}

int pop(int s[], int *t) {
    if (is_Empty(*t)) {
        printf("Stack Underflow\n");
        return -1;
    }
    return s[(*t)--];
}

void moveMinToBottom() {
    int min = INT_MAX, count = 0, x;

    // Find minimum
    while (top != -1) {
        x = pop(stack, &top);
        if (x < min)
            min = x;
        push(temp, &ttop, x);
    }

    // Count min elements
    while (ttop != -1) {
        x = pop(temp, &ttop);
        if (x == min)
            count++;
        else
            push(temp, &ttop, x);  // keep non-mins
    }

    // Push min elements FIRST (goes to bottom)
    while (count--) {
        push(stack, &top, min);
    }

    // Push remaining elements
    while (ttop != -1) {
        push(stack, &top, pop(temp, &ttop));
    }
}


void display() {
    int i;
    for (i = top; i >= 0; i--)
        printf("%d ", stack[i]);
    printf("\n");
}

int main() {
    // Input stack (top-bottom): 5 66 5 8 7
    push(stack, &top, 7);
    push(stack, &top, 8);
    push(stack, &top, 5);
    push(stack, &top, 66);
    push(stack, &top, 5);

    printf("Original stack (top-bottom): ");
    display();

    moveMinToBottom();

    printf("Updated stack (top-bottom): ");
    display();

    return 0;
}
