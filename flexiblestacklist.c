#include<stdio.h>
#include<stdlib.h>

struct Node {
    int value;
    struct Node* next;
};

struct Stack {
    struct Node* head;
};

struct Stack* createStack();
void push(struct Stack* stack, int val);
int pop(struct Stack* stack);
int peek(struct Stack* stack);
void display(struct Stack* stack);

int main() {
    struct Stack* stack1 = createStack();
    struct Stack* stack2 = createStack();

    push(stack1, 10);
    push(stack1, 20);
    push(stack1, 30);
    push(stack2, 40);
    push(stack2, 50);
    push(stack2, 60);
    display(stack1);
    display(stack2);
    printf("%d\n", peek(stack1));
    printf("%d\n", peek(stack2));
    int a = pop(stack1);
    printf("%d\n", a);
    display(stack1);

    return 0;
}

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    return stack;
}

void push(struct Stack* stack, int val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = val;
    newnode->next = stack->head;
    stack->head = newnode;
    
}

int pop(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack Underflow!\n");
        return -1;
    }
    int value = stack->head->value;
    struct Node* temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    return value;
}

int peek(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack is empty!");
        return -1;
    }
    return stack->head->value;
}

void display(struct Stack* stack) {
    struct Node* temp = stack->head;
    printf("[ ");
    while(temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}