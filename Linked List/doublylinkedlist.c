#include <stdio.h>
#include <stdlib.h>  // for malloc

typedef struct Node {
    int value;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct DLL {
    Node* head;
    Node* tail;
} DLL;

DLL* createDLL();
int isEmpty(DLL* dll);
void insertAtHead(DLL* dll, int value);
void insertAtTail(DLL* dll, int value);
void insertAt(DLL* dll, int value, int pos);
void deleteAtHead(DLL* dll);
void deleteAtTail(DLL* dll);
void deleteAt(DLL* dll, int pos);
void displayForward(DLL* dll);
void displayBackward(DLL* dll);

int main() {
    DLL* list = createDLL();
    insertAt(list, 5, 9);
    for(int i = 0; i < 5; i++) insertAtHead(list, i);
    for(int i = 6; i < 10; i++) insertAtTail(list, i);
    displayForward(list);
    displayBackward(list);
    insertAt(list, 10, 3);
    displayForward(list);
    insertAt(list, 10, 15);
    displayForward(list);
    deleteAt(list, 1);
    displayForward(list);
    return 0;
}

DLL* createDLL() {
    DLL* dll = (DLL*)malloc(sizeof(DLL));
    dll->head = NULL;
    dll->tail = NULL;
    return dll;
}

int isEmpty(DLL* dll) {
    return (dll->head == NULL && dll->tail == NULL);
}

void insertAtHead(DLL* dll, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->prev = NULL;
    newNode->next = dll->head;
    if (dll->head != NULL) dll->head->prev = newNode;
    else dll->tail = newNode;
    dll->head = newNode;
}

void insertAtTail(DLL* dll, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = dll->tail;
    if (dll->tail != NULL) dll->tail->next = newNode;
    else dll->head = newNode;
    dll->tail = newNode;
}

void insertAt(DLL* dll, int value, int pos) {
    if (pos == 0 || dll->head == NULL) {
        insertAtHead(dll, value);
        return;
    }
    Node* temp = dll->head;
    for(int i = 0; i < pos - 1 && temp->next != NULL; i++) temp = temp->next;
    if (temp->next == NULL) {
        insertAtTail(dll, value);
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}

void deleteAtHead(DLL* dll) {
    if (isEmpty(dll)) {
        printf("List is Empty!");
        return;
    }
    Node* temp = dll->head;
    if (dll->head == dll->tail) dll->head = dll->tail = NULL;
    else {
        dll->head = dll->head->next;
        dll->head->prev = NULL;
    }
    free(temp);
}

void deleteAtTail(DLL* dll) {
    if (isEmpty(dll)) {
        printf("List is Empty!");
        return;
    }
    Node* temp = dll->tail;
    if (dll->head == dll->tail) dll->head = dll->tail = NULL;
    else {
        dll->tail = dll->tail->prev;
        dll->tail->next = NULL;
    }
    free(temp);
}

void deleteAt(DLL* dll, int pos) {
    if (pos == 0) {
        deleteAtHead(dll);
        return;
    }
    Node* temp = dll->head;
    for(int i = 0; i < pos && temp->next != NULL; i++) temp = temp->next;
    if (temp->next == NULL) {
        deleteAtTail(dll);
        return;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    free(temp);
}

void displayForward(DLL* dll) {
    Node* temp = dll->head;
    printf("\n[ ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->next;
    }
    printf("]\n");   
}

void displayBackward(DLL* dll) {
    Node* temp = dll->tail;
    printf("\n[ ");
    while (temp != NULL) {
        printf("%d ", temp->value);
        temp = temp->prev;
    }
    printf("]\n");   
}
