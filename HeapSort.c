#include <stdio.h>

//function to swap two elements
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to heapify a subtree
void heapify(int arr[], int n, int i) {
    int largest = i; // largest as root
    int left = 2 * i + 1; // left child 
    int right = 2 * i + 2; // right child 

    //if left child is larger than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    //if right child is larger than largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    //if largest is not root
    if (largest != i) {
        swap(&arr[i], &arr[largest]);

        //recursively heapify the sub-trees
        heapify(arr, n, largest);
    }
}

//heap sort
void heapSort(int arr[], int n) {
    //build heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    //extract an element from heap
    for (int i = n - 1; i > 0; i--) {
        //current root to end
        swap(&arr[0], &arr[i]);

        //max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

//print array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {5, 7, 4, 9, 3, 1, 6, 3, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Given array is \n");
    printArray(arr, n);

    heapSort(arr, n);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}
