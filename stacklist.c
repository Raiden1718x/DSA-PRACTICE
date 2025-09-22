#include<stdio.h>
#include<stdlib.h>

struct Stack {
    int value;
    struct Stack* next;
};

struct Stack* head = NULL;

void push(int val);
int pop();
int peek();
void display();

int main() {
    printf("%d\n\n", pop());
    push(0);
    push(10);
    push(13);
    push(12);
    push(1);
    display();
    printf("%d\n\n", pop());
    display();
    
    return 0;
}

void push(int val) {
    struct Stack* newnode = (struct Stack*)malloc(sizeof(struct Stack));
    newnode->value = val;
    newnode->next = head;
    head = newnode;
    
}

int pop() {
    if (head == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = head-> value;
    struct Stack* temp = head;
    head = head->next;
    free(temp);
    return value;
}

int peek() {
    if (head == NULL) {
        printf("Stack is empty!");
        return -1;
    }
    return head->value;
}

void display() {
    struct Stack* temp = head;
    printf("[ ");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}
