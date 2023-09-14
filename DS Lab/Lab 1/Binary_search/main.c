#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return -1; // Element not found
}

int main() {
    int myArray[] = {12, 22, 34, 45, 67, 89};
    int n = sizeof(myArray) / sizeof(myArray[0]);
    int elementToFind = 67;

    int result = binarySearch(myArray, 0, n - 1, elementToFind);

    if (result != -1) {
        printf("Element %d found at index %d\n", elementToFind, result);
    } else {
        printf("Element %d not found in the list.\n", elementToFind);
    }

    return 0;
}
