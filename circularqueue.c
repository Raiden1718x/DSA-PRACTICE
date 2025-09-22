#include <stdio.h>

#define SIZE 100

int arr[SIZE];

int FRONT = -1;
int REAR = -1;

int isEmpty();
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
    return 0;
}

int isEmpty() {
    if (FRONT == -1 && REAR == -1) return 1;
    else return 0;
}

void enqueue(int value) {
    if ((REAR + 1) % SIZE == FRONT) {
        printf("Queue Overflow!");
        return;
    }
    if (isEmpty()) FRONT = REAR = 0;
    else REAR = (REAR + 1) % SIZE;
    arr[REAR] = value;;
}

int dequeue() {
    
    if (isEmpty()) {
        printf("Queue Underflow!");
        return -1;
    }
    int value = arr[FRONT];
    if (REAR == FRONT) FRONT = REAR = -1;
    else FRONT = (FRONT + 1) % SIZE;
    return value;
}

int peek() {
    return arr[FRONT];
}

void display() {
    int i = FRONT;
    printf("\n[");
    while (1) {
        printf("%d ", arr[i]);
        if (i == REAR) break;
        i = (i + 1) % SIZE;
    }
    printf("]\n");
    
}