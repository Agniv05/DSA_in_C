/* Space complexity measures the amount of memory an algorithm or program uses in relation to the input size, 𝑛. 
It accounts for both the space required for the variables and any additional data structures used, like arrays,
lists, or recursion stacks.

How to Find Space Complexity:

Identify Different Types of Memory Usage:
Fixed Part (Constant Space): This includes variables, constants, and temporary storage that do not depend on the
input size (e.g., a few integer variables).
Variable Part (Dependent on Input Size): Memory that depends on 𝑛, like arrays, lists, or recursion call stacks, 
increases with the input size.
Analyze Data Structures:

If your program uses data structures like arrays, hash tables, trees, or linked lists, evaluate their sizes based 
on the input size. For instance, an array of size 𝑛 contributes 𝑂(𝑛) space complexity.

Account for Recursive Calls:
If your algorithm is recursive, each recursive call adds a new frame to the call stack. For a recursive function that
calls itself 𝑛 times, this adds 𝑂(𝑛) space. For divide-and-conquer recursions, like 
binary recursion, the space can be 𝑂(log 𝑛).

Ignore Constants and Lower Order Terms:
Like with time complexity, ignore constant factors and non-dominant terms when calculating the final space complexity.

*/

#include <stdio.h>
#include <stdlib.h>

// Function to add one to a number
// Space complexity: O(1)
int add_one(int n) {
    int result = n + 1; // Add 1 to the input number
    return result;
}

// Function to create an array of size `n` initialized to 0
// Space complexity: O(n)
int* create_array(int n) {
    int* arr = (int*)malloc(n * sizeof(int)); // Dynamically allocate memory for the array
    for (int i = 0; i < n; i++) {
        arr[i] = 0; // Initialize each element to 0
    }
    return arr;
}

// Function to create a matrix of size `n x n` initialized to 0
// Space complexity: O(n^2)
int** create_matrix(int n) {
    int** matrix = (int**)malloc(n * sizeof(int*)); // Allocate memory for rows
    for (int i = 0; i < n; i++) {
        matrix[i] = (int*)malloc(n * sizeof(int)); // Allocate memory for columns
        for (int j = 0; j < n; j++) {
            matrix[i][j] = 0; // Initialize each element to 0
        }
    }
    return matrix;
}

// Recursive implementation of binary search
// Time complexity: O(log n)
// Space complexity: O(log n) due to recursion stack frames
int binary_search(int arr[], int target, int low, int high) {
    if (low > high) { // Base case: target not found
        return -1;
    }

    int mid = (low + high) / 2; // Find the middle index
    if (arr[mid] == target) {
        return mid; // Target found
    } else if (arr[mid] < target) {
        return binary_search(arr, target, mid + 1, high); // Search in the right half
    } else {
        return binary_search(arr, target, low, mid - 1); // Search in the left half
    }
}

// Main function to demonstrate the above functionality
int main() {
    // Example usage of add_one
    int number = 5;
    printf("Result of add_one: %d\n", add_one(number));

    // Example usage of create_array
    int n = 5;
    int* arr = create_array(n);
    printf("Created array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr); // Free dynamically allocated memory

    // Example usage of create_matrix
    int size = 3;
    int** matrix = create_matrix(size);
    printf("Created matrix:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
        free(matrix[i]); // Free memory for each row
    }
    free(matrix); // Free memory for the matrix

    // Example usage of binary_search
    int array[] = {1, 3, 5, 7, 9, 11};
    int target = 5;
    int low = 0;
    int high = sizeof(array) / sizeof(array[0]) - 1;
    int result = binary_search(array, target, low, high);
    if (result != -1) {
        printf("Element %d found at index %d\n", target, result);
    } else {
        printf("Element %d not found in the array\n", target);
    }

    return 0;
}