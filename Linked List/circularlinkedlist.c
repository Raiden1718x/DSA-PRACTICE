#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int value;
    struct Node* next;
} Node;

typedef struct CLL {
    Node* head;
    Node* tail;
} CLL;

CLL* createCLL();
int isEmpty(CLL* cll);
void insertAtHead(CLL* cll, int value);
void insertAtTail(CLL* cll, int value);
void insertAt(CLL* cll, int value, int pos);
void display(CLL* cll);

int main() {

    CLL* list = createCLL();
    for(int i = 0; i < 5; i++) insertAtHead(list, i);
    for(int i = 6; i < 10; i++) insertAtTail(list, i);
    display(list);
    insertAt(list, 10, 4);
    display(list);

    return 0;
}

CLL* createCLL() {
    CLL* list = (CLL*)malloc(sizeof(CLL));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

int isEmpty(CLL* cll) {
    return (cll->head == NULL && cll->tail == NULL);
}

void insertAtHead(CLL* cll, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (isEmpty(cll)) {
        newNode->next = newNode;
        cll->head = cll->tail = newNode;
        return;
    }
    newNode->next = cll->head;
    cll->head = newNode;
    cll->tail->next = cll->head;
}

void insertAtTail(CLL* cll, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    if (isEmpty(cll)) {
        newNode->next = newNode;
        cll->head = cll->tail = newNode;
        return;
    }
    newNode->next = cll->head;
    cll->tail->next = newNode;
    cll->tail = newNode;
}

void insertAt(CLL* cll, int value, int pos) {
    if (pos == 0 || isEmpty(cll)) {
        insertAtHead(cll, value);
        return;
    }
    Node* temp = cll->head;
    for (int i = 0; i < pos -1 && temp != cll->tail; i++) temp = temp->next;
    if (temp == cll->tail) {
        insertAtTail(cll, value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = temp->next;
    temp->next = newNode;
}

void display(CLL* cll) {
    if (isEmpty(cll)) {
        printf("[ ]");
        return;
    }
    
    Node* temp = cll->head;
    printf("\n[ ");
    while(1) {
        printf("%d ", temp->value);
        if (temp == cll->tail) break;
        temp = temp->next;
    }
    printf("]\n");
}