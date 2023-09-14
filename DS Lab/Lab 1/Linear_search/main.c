#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int myArray[] = {12, 45, 67, 89, 34, 22};
    int n = sizeof(myArray) / sizeof(myArray[0]);
    int elementToFind = 67;

    int result = linearSearch(myArray, n, elementToFind);

    if (result != -1) {
        printf("Element %d found at index %d\n", elementToFind, result);
    } else {
        printf("Element %d not found in the list.\n", elementToFind);
    }

    return 0;
}
