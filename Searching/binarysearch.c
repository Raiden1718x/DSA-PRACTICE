//Note: Binary Search only works for a sorted array
#include <stdio.h>

int binarySearch(int target, int arr[], int size);
void display(int arr[], int size);

int main() {
    int size = 5;
    int arr[] = {1, 2, 3, 4, 5};
    int target;
    printf("Enter target\n");
    scanf("%d", &target);
    display(arr, size);
    int index = binarySearch(target, arr, size);
    printf("%d is found at index %d", target, index);

    return 0;
    
}

//Returns the index of the targeted value in array. If not found, returns -1.
int binarySearch(int target, int arr[], int size) {
    int found = 0;
    int start = 0, end = size - 1, mid;
    while(start <= end) {
        mid = (start + end)/2;
        if(target == arr[mid]) {
            found = 1; 
            break;
        }
        if (target > arr[mid]) start = mid + 1;
        if (target < arr[mid]) end = mid - 1;
    }
    if (found) return mid;
    else return -1;
}

void display(int arr[], int size) {
    printf("\n[ ");
    for(int i = 0; i < size; i++) printf("%d ", arr[i]);
    printf("]\n");
}