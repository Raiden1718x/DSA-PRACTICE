#include <stdio.h>

#define SIZE 100
int arr[SIZE];
int FRONT = -1;
int REAR = -1;

void enqueue(int value);
int dequeue();
int peek();
void display();

int main() {
    for (int i = 0; i <= 99; i++) enqueue(i + 1);
    display();
    dequeue();
    display();
    enqueue(1);
    return 0;
}

void enqueue(int value) {
    if (REAR == SIZE - 1) {
        printf("Stack Overflow!");
        return;
    }
    if (FRONT == -1) FRONT = 0;
    arr[++REAR] = value;
}

int dequeue() {
    if (REAR < FRONT || FRONT == -1) {
        printf("Stack Underflow!");
        return -1;
    }
    int value = arr[FRONT];
    FRONT++;
    return value;
}

int peek() {
    if (REAR < FRONT || FRONT == -1) {
        printf("Stack is Empty!");
        return -1;
    }
    return arr[FRONT];
}

void display() {
    printf("\n[ ");
    for (int i = FRONT; i <= REAR; i++) printf("%d ", arr[i]);
    printf("]\n");
}