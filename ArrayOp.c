#include <stdio.h>
#include <stdlib.h>

// Function to find the index of the first occurrence of a number in an array
int find_index(int arr[], int size, int x) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            return i; // Return the index of the first occurrence
        }
    }
    return -1; // Return -1 if the element is not found
}

// Function to count occurrences of a number in an array
int count_occurrences(int arr[], int size, int x) {
    int count = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == x) {
            count++;
        }
    }
    return count;
}

// Function to sort an array in ascending order (Bubble Sort used here for simplicity)
void sort_array(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap arr[j] and arr[j + 1]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Function to reverse an array
void reverse_array(int arr[], int size) {
    for (int i = 0; i < size / 2; i++) {
        // Swap elements from both ends
        int temp = arr[i];
        arr[i] = arr[size - i - 1];
        arr[size - i - 1] = temp;
    }
}

// Function to calculate the sum of elements in an array
int sum_array(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// Function to find the minimum element in an array
int find_min(int arr[], int size) {
    int min = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }
    return min;
}

// Function to find the maximum element in an array
int find_max(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

// Function to create an array of squares of another array
void calculate_squares(int arr[], int size, int squares[]) {
    for (int i = 0; i < size; i++) {
        squares[i] = arr[i] * arr[i];
    }
}

int main() {
    int arr[] = {1, 10, 15, 19, 10, 32, 27, 7, 11};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    // Find index of the first occurrence of 15
    int index = find_index(arr, size, 15);
    printf("Index of 15: %d\n", index);
    
    // Count occurrences of 10
    int count = count_occurrences(arr, size, 10);
    printf("Count of 10: %d\n", count);
    
    // Sort the array
    sort_array(arr, size);
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Reverse the array
    reverse_array(arr, size);
    printf("Reversed array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Length of the array
    printf("Length of array: %d\n", size);
    
    // Sum of elements in the array
    int sum = sum_array(arr, size);
    printf("Sum of array elements: %d\n", sum);
    
    // Minimum element in the array
    int min = find_min(arr, size);
    printf("Minimum element: %d\n", min);
    
    // Maximum element in the array
    int max = find_max(arr, size);
    printf("Maximum element: %d\n", max);
    
    // Squares of elements in another array
    int arrt[] = {1, 2, 3};
    int arrt_size = sizeof(arrt) / sizeof(arrt[0]);
    int squares[arrt_size];
    calculate_squares(arrt, arrt_size, squares);
    printf("Squares of elements: ");
    for (int i = 0; i < arrt_size; i++) {
        printf("%d ", squares[i]);
    }
    printf("\n");

    return 0;
}