#include <stdio.h>

void bubbleSort(int arr[], int size);
void display(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {3, 5, 2, 1, 4};
    bubbleSort(arr, size);
    display(arr, size);
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if(arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void display(int arr[], int size) {
    printf("\n[ ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}