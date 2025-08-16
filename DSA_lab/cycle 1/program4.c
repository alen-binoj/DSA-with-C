#include <stdio.h>
//sort list in descending order in different sort methods
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[maxIdx]) {
                maxIdx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main() {
    
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    

    printf("Original array: \n");
    printArray(arr, n);

    printf("1. Bubble Sort\n2. Selection Sort\n3. Insertion Sort\n");
    int choice;
    printf("Choose a sorting method: ");
    scanf("%d", &choice);
    switch (choice) {
        case 1:
            bubbleSort(arr, n);
            printf("Sorted array using Bubble Sort: \n");
            printArray(arr, n);
            break;
        case 2:
            selectionSort(arr, n);
            printf("Sorted array using Selection Sort: \n");
            printArray(arr, n);
            break;
        case 3:
            insertionSort(arr, n);
            printf("Sorted array using Insertion Sort: \n");
            printArray(arr, n);
            break;
        default:
            printf("Invalid choice!\n");
            return 1;
    }
    
}
