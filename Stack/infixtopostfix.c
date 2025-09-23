#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

struct Node {
    char value;
    struct Node* next;
};

struct Stack {
    struct Node* head;
};


void infixToPostfix(char infix[]);
int precedence(char op);
int isOperator(char op);
struct Stack* createStack();
int isEmpty(struct Stack* stack);
void push(struct Stack* stack, char val);
char pop(struct Stack* stack);
char peek(struct Stack* stack);
void display(struct Stack* stack);

int main() {
    char infix[] = "(A+B/C*(D+E)-F)";
    infixToPostfix(infix);

    return 0;
}

void infixToPostfix(char infix[]) {
    struct Stack* stack = createStack();
    char postfix[100];
    int i = 0;
    int k = 0;
    while (infix[i] != '\0') {
        if (isalnum(infix[i])) postfix[k++] = infix[i];
        else if (infix[i] == '(') push(stack, infix[i]);
        else if (infix[i] == ')') {
            while(peek(stack) != '(' && !isEmpty(stack)) postfix[k++] = pop(stack);
            pop(stack);
        }
        else if (isOperator(infix[i])) {
            while (precedence(infix[i]) <= precedence(peek(stack)) && !isEmpty(stack)) postfix[k++] = pop(stack);
            push(stack, infix[i]);
        }
        i++;
    }
    while (!isEmpty(stack)) postfix[k++] = pop(stack);
    postfix[k] = '\0';
    printf("Postfix: %s\n", postfix);
    
}

/* -------- Stack implementation -------- */

struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->head = NULL;
    return stack;
}

int isEmpty(struct Stack* stack) {
    return stack->head == NULL;
}

void push(struct Stack* stack, char val) {
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->value = val;
    newnode->next = stack->head;
    stack->head = newnode;
    
}

char pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow!\n");
        return '\n';
    }
    char value = stack->head->value;
    struct Node* temp = stack->head;
    stack->head = stack->head->next;
    free(temp);
    return value;
}

char peek(struct Stack* stack) {
    if (stack->head == NULL) {
        printf("Stack is empty!");
        return '\n';
    }
    return stack->head->value;
}

void display(struct Stack* stack) {
    struct Node* temp = stack->head;
    printf("[ ");
    while(temp != NULL) {
        printf("%c ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}

/* -------- Helpers -------- */

int precedence(char op) {
    switch (op) {
        case '^': return 3;
        case '*': case '/': return 2;
        case '+': case '-': return 1;
        default: return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}