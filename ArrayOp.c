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



// Function to print the array
void print_array(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to append an element to the array
int append(int arr[], int size, int element, int capacity) {
    if (size >= capacity) {
        printf("Error: Array is full.\n");
        return size; // No changes made
    }
    arr[size] = element; // Add element at the end
    return size + 1;     // Increment size
}

// Function to pop the last element of the array
int pop(int arr[], int size, int *popped_element) {
    if (size == 0) {
        printf("Error: Array is empty.\n");
        return size; // No changes made
    }
    *popped_element = arr[size - 1]; // Store the last element
    return size - 1;                 // Decrement size
}

// Function to pop an element at a specific index
int pop_at_index(int arr[], int size, int index, int *popped_element) {
    if (index < 0 || index >= size) {
        printf("Error: Invalid index.\n");
        return size; // No changes made
    }
    *popped_element = arr[index]; // Store the element at the given index
    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1]; // Shift elements left
    }
    return size - 1; // Decrement size
}

// Function to alter an element at a specific index
void alter_element(int arr[], int index, int new_value) {
    arr[index] = new_value; // Change the value at the specified index
}

int main() {
    // Initialize an array with a fixed capacity
    int capacity = 10;               // Maximum capacity of the array
    int arr[capacity] = {1, 2, 3};   // Initial elements
    int size = 3;                    // Current size of the array

    // Append an element
    size = append(arr, size, 4, capacity);
    printf("After push: ");
    print_array(arr, size);          // Output: [1, 2, 3, 4]

    // Pop the last element
    int last_element;
    size = pop(arr, size, &last_element);
    printf("After pop: ");
    print_array(arr, size);          // Output: [1, 2, 3]
    printf("Popped element: %d\n", last_element); // Output: 4

    // Pop an element at a specific index
    int element_at_index_1;
    size = pop_at_index(arr, size, 1, &element_at_index_1);
    printf("After popping index 1: ");
    print_array(arr, size);          // Output: [1, 3]
    printf("Popped element at index 1: %d\n", element_at_index_1); // Output: 2

    // Alter element at index 1
    alter_element(arr, 1, 10);
    printf("After alteration: ");
    print_array(arr, size);          // Output: [1, 10]

    // Second example with a new array
    int arrt[capacity] = {1, 2, 3};
    size = 3;

    // Append an element
    size = append(arrt, size, 4, capacity);
    printf("After push: ");
    print_array(arrt, size);         // Output: [1, 2, 3, 4]

    // Pop the last element
    size = pop(arrt, size, &last_element);
    printf("After pop: ");
    print_array(arrt, size);         // Output: [1, 2, 3]

    // Alter element at index 1
    alter_element(arrt, 1, 10);
    printf("After alteration: ");
    print_array(arrt, size);         // Output: [1, 10, 3]

    return 0;
}