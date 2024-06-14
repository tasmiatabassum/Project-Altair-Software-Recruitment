#include <stdio.h>

//function to swap two elements
void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//partition function
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // last element as pivot
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

//QuickSort 
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high); //partitioning index
        quickSort(arr, low, pi - 1); //recursively sort elements before partition
        quickSort(arr, pi + 1, high); //recursively sort elements after partition
    }
}

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

    quickSort(arr, 0, n - 1);

    printf("\nSorted array is \n");
    printArray(arr, n);

    return 0;
}
