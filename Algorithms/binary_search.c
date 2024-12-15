#include <stdio.h>

// Function to perform binary search
int binarySearch(int arr[], int size, int target) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        // Check if the target is at the middle
        if (arr[mid] == target) {
            return mid;
        }

        // If target is smaller than the middle element, search the left half
        if (arr[mid] > target) {
            right = mid - 1;
        } else {
            // If target is larger, search the right half
            left = mid + 1;
        }
    }

    // Return -1 if the target is not found
    return -1;
}

int main() {
    int arr[] = {2, 4, 6, 8, 10, 12, 14}; // Sorted array
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    printf("Enter the number to search: ");
    scanf("%d", &target);

    int result = binarySearch(arr, size, target);

    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array.\n");
    }

    return 0;
}
