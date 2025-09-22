#include<stdio.h>
#include<stdlib.h>

typedef struct {
    int value;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
} Queue;

Queue* initQueue();
void enqueue(Queue* queue, int value);
int dequeue(Queue* queue);
int peek(Queue* queue);
void display(Queue* queue);

int main() {
    Queue* q1 = initQueue();
    Queue* q2 = initQueue();
    for (int i = 0; i < 10; i++) enqueue(q1, i);
    display(q1);
    int a = dequeue(q1);
    display(q1);
    enqueue(q1, a + 10);
    display(q1);
    enqueue(q2, peek(q1) + 10);
    display(q2);
    return 0;
}

Queue* initQueue() {
    Queue* queue = (Queue*)malloc(sizeof(Queue));
    queue->head = NULL;
    queue->tail = NULL;
    return queue;
}

void enqueue(Queue* queue, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->value = value;
    if (queue->head == NULL) {
        queue->head = newNode;
        queue->tail = newNode;
        return;
    } else {
        queue->tail->next = newNode;
        queue->tail = queue->tail->next;
    }
}

int dequeue(Queue* queue) {
    if (queue->head == NULL) {
        printf("Stack is empty!");
        return -1;
    }
    int value = queue->head->value;
    Node* temp = queue->head;
    queue->head = queue->head->next;
    if (queue->head == NULL) queue->tail ==NULL;
    free(temp);
    return value;
}

int peek(Queue* queue) {
    return queue->head->value;
}

void display(Queue* queue) {
    Node* temp = queue->head;
    printf("\n[");
    while (temp != NULL) {
        printf(" %d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");
}
