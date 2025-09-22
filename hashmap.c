#include<stdio.h>
#include<stdlib.h>

typedef enum {
    INTEGER,
    STRING,
    FLOAT
} DataType;

typedef struct {
    void* key;
    void* value;    
    struct Node* next;
} Node;

typedef struct {
    struct Node* head;
    DataType keyType;
    DataType valueType;
}  HashMap;

HashMap* createHashMap(DataType keyType, DataType valueType);
void insert(HashMap* map, void* key, void* value);
int compare(void* k1, void* k2, DataType type);
void* get(HashMap* map, void* key);
void display(HashMap* map);

int main() {
    HashMap* map = createHashMap(INTEGER, STRING);

    int k1 = 10, k2 = 20;
    char* v1 = "Hello";
    char* v2 = "World";

    insert(map, &k1, v1);
    insert(map, &k2, v2);
    printf("%s", get(map, &k2));

    display(map); // Output: [ 20 -> World; 10 -> Hello; ]
    return 0;
}

HashMap* createHashMap(DataType keyType, DataType valueType) {
    HashMap* map = (HashMap*)malloc(sizeof(HashMap));
    map->head = NULL;
    map->keyType = keyType;
    map->valueType = valueType;
    return map;
}

void insert(HashMap* map, void* key, void* value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = NULL;
    if (map->head == NULL) map->head = newNode;
    else {
        Node* temp = map->head;
        while(temp->next != NULL) temp = temp->next;
        temp->next = newNode;
    }
}

int compare(void* k1, void* k2, DataType type) {
    if (type == INTEGER) return (*(int*)k1 == *(int*)k2);
    if (type == STRING)  return strcmp((char*)k1, (char*)k2) == 0;
    if (type == FLOAT)   return (*(float*)k1 == *(float*)k2);
    return 0;
}


void* get(HashMap* map, void* key) {
    Node* temp = map->head;
    while(temp != NULL) {
        if (compare(key, temp->key, map->keyType)) return temp->value;
        else temp = temp->next;
    }
    return NULL;
}

void display(HashMap* map) {
    Node* temp = map->head;
    printf("[ ");
    while (temp != NULL) {

        switch (map->keyType) {
            case INTEGER:
                printf("%d", *(int*)temp->key);
                break;
            case STRING:
                printf("\"%s\"", (char*)temp->key);
                break;
            case FLOAT:
                printf("%.2f", *(float*)temp->key);
                break;
        }

        printf(" : ");

        switch (map->valueType) {
            case INTEGER:
                printf("%d", *(int*)temp->value);
                break;
            case STRING:
                printf("\"%s\"", (char*)temp->value);
                break;
            case FLOAT:
                printf("%.2f", *(float*)temp->value);
                break;
        }

        printf(" ");
        temp = temp->next;
    }
    printf("]\n");
}




