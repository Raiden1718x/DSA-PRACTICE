#include <stdio.h>

void insertionSort(int arr[], int size);
void display(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {3, 5, 2, 1, 4};
    insertionSort(arr, size);
    display(arr, size);
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int j = i;
        while (arr[j] < arr[j - 1] && j > 0) {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void display(int arr[], int size) {
    printf("\n[ ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}