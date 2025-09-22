#include <stdio.h>

int linearSearch(int target, int arr[], int size);
void display(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {3, 5, 2, 1, 4};
    int target;
    printf("Enter target\n");
    scanf("%d", &target);
    display(arr, size);
    int index = linearSearch(target, arr, size);
    printf("%d is found at index %d", target, index);

    return 0;
    
}

//Returns the index of the targeted value in array. If not found, returns -1.
int linearSearch(int target, int arr[], int size) {
    int i, found = 0;
    for (i = 0; i < size; i++) {
        if(arr[i] == target) {
            found = 1;
            break;
        }
    }
    if (found) return i;
    else return -1;
}

void display(int arr[], int size) {
    printf("\n[ ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}