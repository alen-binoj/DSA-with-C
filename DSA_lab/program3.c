#include <stdio.h>

void intersection(int arr1[], int arr2[], int arr[], int n1, int n2, int *n3) {
    *n3 = 0;
    for (int i = 0; i < n1; i++) {
        for (int j = 0; j < n2; j++) {
            if (arr1[i] == arr2[j]) {
                int alreadyPresent = 0;
                for (int k = 0; k < *n3; k++) {
                    if (arr[k] == arr1[i]) {
                        alreadyPresent = 1;
                        break;
                    }
                }
                if (!alreadyPresent) {
                    arr[*n3] = arr1[i];
                    (*n3)++;
                }
                break; // avoid duplicates if arr1[i] matches multiple times in arr2
            }
        }
    }
}

int main() {
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {3, 4, 5};
    int arr3[10]; // to store intersection
    int n3;

    intersection(arr1, arr2, arr3, 4, 3, &n3);

    printf("Intersection of the two arrays: ");
    for (int i = 0; i < n3; i++) {
        printf("%d ", arr3[i]);
    }
    printf("\n");
}
