#include<stdio.h>

#define MAX 100
int arr[MAX];
int TOP = -1;

void push(int value);
int pop();
int peek();
void display();

int main() {
    for (int i = 0; i <= 9; i++) push(i);
    
    display();
    int a = pop();
    display();
    return 0;
}

void push(int value) {
    if (TOP == MAX -1) {
        printf("Stack Overflow!");
        return;
    }
    arr[++TOP] = value;
}

int pop() {
    if (TOP == -1) {
        printf("Stack Underflow!");
        return -1;
    }
    return arr[TOP--];
}

int peek() {
    if (TOP == -1) {
        printf("Stack is Empty");
        return -1;
    }
    return arr[TOP];
}

void display() {
    printf("\n[ ");
    for (int i = TOP; i >= 0; i--) printf("%d ", arr[i]);
    printf("]\n");
}

