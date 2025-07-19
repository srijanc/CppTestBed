#include <stdio.h>

void reverse(int* array, int numElements) {
    int i = 0;
    int j = numElements - 1;

    while (i < j) {
        int temp = array[i];
        array[i++] = array[j];
        array[j--] = temp;
    }
}

int* mergeSortedArray(int* array1, int numElements1, int* array2, int numElements2) {
    int i = 0, j = 0, k = 0;
    int* result;
    
    while (i < numElements1 && j < numElements2) {
        if (array1[i] <= array2[j]) {
            result[k++] = array1[i++];
        } else {
            result[k++] = array2[j++];
        }
    }

    while (i < numElements1) {
        result[k++] = array1[i++];
    }

    while (j < numElements2) {
        result[k++] = array2[j++];
    }

    return result;
}

int main() {
    int array[4] = {1,2,3,4};
    reverse(array, 4);

    for (int i = 0; i < 4; i++) {
        printf("%d ", array[i]);
    }

    printf("\n");

    int a[4] = {1, 4, 6, 8};
    int b[6] = {3, 5, 5, 6, 9, 10};
    int* merged;

    merged = mergeSortedArray(a, 4, b, 6);

    for (int i = 0; i < 10; i++) {
        printf("%d ", merged[i]);
    }

    printf("\n");
}
