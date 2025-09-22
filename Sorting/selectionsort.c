#include <stdio.h>

void selectionSort(int arr[], int size);
void display(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {3, 5, 2, 1, 4};
    selectionSort(arr, size);
    display(arr, size);
}

void selectionSort(int arr[], int size) {
    
    for (int i = 0; i < size; i++) {
        int min = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

void display(int arr[], int size) {
    printf("\n[ ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}