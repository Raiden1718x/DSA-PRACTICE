#include <stdio.h>
#include <stdlib.h>   // for malloc

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;  // head pointer

void delete(int index) {
    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }
    
    struct Node* temp = head;
    if(index == 0) {
        head = head->next; // Move head to next node
        free(temp); // Free the old head
    }

    struct Node* temp = head;
}

void insert(int value, int index) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (index == 0) {  // insert at head
        newNode->next = head;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 0; i < index - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Index out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;   // ✅ link the new node
}

void printList() {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    // Create initial list 1 -> 2 -> 3
    head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    n2->data = 2;
    n3->data = 3;
    head->next = n2;
    n2->next = n3;
    n3->next = NULL;
    printList();  // Expected output: 1 2 3
    delete(0);  // Delete head (1)
    printList();  // Expected output: 2 3

    return 0;
}
