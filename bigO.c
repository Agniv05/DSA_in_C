/* Big O Notation :

Big O notation is a mathematical concept used in computer science to describe the efficiency of algorithms,
especially in terms of their time and space complexity. It provides an upper bound on the growth rate of an
algorithm’s runtime or memory usage as the input size increases, focusing on the worst-case scenario.

 Big O notation helps estimate how an algorithm’s performance changes with larger inputs. For instance, if an
algorithm has a complexity of 𝑂(𝑛), its runtime grows linearly with the input size.

O(1): Constant time – the algorithm’s runtime is constant regardless of input size.
O(log n): Logarithmic time – the algorithm’s runtime grows slowly as input size increases.
O(n): Linear time – the runtime grows proportionally to the input size.
O(n log n): Linearithmic time – typical for efficient sorting algorithms like mergesort.
O(n²): Quadratic time – the runtime grows proportional to the square of the input size, common in nested loops.
O(2ⁿ): Exponential time – runtime doubles with each additional input, often impractical for large inputs.
O(n!): Factorial time – very inefficient, where runtime grows faster than exponential.


Example:

time= a*n + b
Step 1: keep fasteest growing term
        time = a*n
Step 2: drop all constants
        time = O(n)


To calculate the time complexity of a program, you analyze its code structure and count the number of fundamental 
operations it performs in relation to the input size, 𝑛. Here’s a systematic approach to calculating time complexity:

Step-by-Step Guide:
Identify Basic Operations:

A basic operation could be an assignment, comparison, arithmetic operation, or any single statement that executes in 
constant time, 𝑂(1).

Analyze Loops:

Simple Loops: A single loop that runs 𝑛 times contributes 𝑂(𝑛) complexity.
Nested Loops: If one loop runs 𝑛 times and contains another loop that also runs 𝑛 times, the complexity becomes 𝑂(𝑛×𝑛)=𝑂(𝑛2).
Dependent Loops: If a loop’s iterations depend on the size of the input in a way that reduces over time (e.g., 𝑛,𝑛/2,𝑛/4,…n,n/2,n/4,…), 
this often results in a logarithmic 𝑂(log 𝑛) complexity.

Analyze Conditional Statements:

Conditionals themselves don’t add complexity, but if a program has branching (e.g., if-else), analyze each branch separately and take the branch with the largest complexity.
Analyze Function Calls:

For recursive functions, you can use a recurrence relation to express the function’s time complexity and then solve it (e.g., by the Master Theorem for common recurrence patterns).
For example, a recursive function calling itself twice with input size 𝑛/2 has complexity 𝑇(𝑛)=2𝑇(𝑛/2)+𝑂(𝑛) , T(n)=2T(n/2)+O(n), which simplifies to 𝑂(𝑛log𝑛).

Ignore Constants and Non-Dominant Terms:
When you reach a final expression, ignore constants and lower-order terms since they don’t impact the growth rate for large inputs.
For example, 
5𝑛2+3𝑛+15 simplifies to 𝑂(𝑛2) because 𝑛2 grows faster than 𝑛 as 𝑛 becomes large.

Examples:

Single Loop:
for i in range(n):
    print(i)
This loop runs 𝑛 times, so its complexity is 𝑂(𝑛).

Nested Loop:
for i in range(n):
    for j in range(n):
        print(i, j)
The inner loop runs 𝑛 times for each of the 𝑛 iterations of the outer loop, resulting in 𝑂(𝑛×𝑛)=𝑂(𝑛2)


Logarithmic Complexity:
i = 1
while i < n:
    print(i)
    i *= 2
The variable 𝑖 doubles each time, so this loop runs approximately log 2𝑛 times, resulting in 𝑂(log 𝑛).

Recursive Function:
def fibonacci(n):
    if n <= 1:
        return n
    return fibonacci(n-1) + fibonacci(n-2)
This function has exponential complexity 𝑂(2𝑛) due to the two recursive calls with each decrement of 𝑛.




*/

#include <stdio.h>

// Function to calculate the square of each number in an array
// Time complexity = O(n)
void get_squared_no(int numbers[], int size, int squared_nos[]) {
    for (int i = 0; i < size; i++) {
        squared_nos[i] = numbers[i] * numbers[i]; // Square each element
    }
}

// Function to calculate the P/E ratio at a given index
// Time complexity = O(1)
float calculate_pe(float price[], float ep[], int index) {
    return price[index] / ep[index]; // Direct access to calculate P/E
}

// Function to find duplicates in an array using nested loops
// Time complexity = O(n^2)
void find_duplicates(int numbers[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] == numbers[j]) { // Check for duplicate
                printf("%d is a duplicate.\n", numbers[i]);
                break;
            }
        }
    }
}

// Function to find the first duplicate and print 1 for all its occurrences
// Time complexity = O(n^2) (dominant term)
void handle_duplicates(int numbers[], int size) {
    int duplicate = -1; // Variable to store the first duplicate
    
    // First loop: Find the first duplicate
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (numbers[i] == numbers[j]) {
                duplicate = numbers[i];
                break;
            }
        }
        if (duplicate != -1) break; // Exit if duplicate is found
    }

    // Second loop: Print 1 for every occurrence of the duplicate
    if (duplicate != -1) {
        for (int i = 0; i < size; i++) {
            if (numbers[i] == duplicate) {
                printf("1\n");
            }
        }
    }
}

int main() {
    // Example usage for squaring numbers
    int numbers[] = {2, 5, 8, 10, 24};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int squared_nos[size];
    get_squared_no(numbers, size, squared_nos);
    
    printf("Squared numbers:\n");
    for (int i = 0; i < size; i++) {
        printf("%d ", squared_nos[i]);
    }
    printf("\n");

    // Example usage for P/E calculation
    float price[] = {100.0, 200.0, 300.0};
    float ep[] = {10.0, 20.0, 30.0};
    int index = 1; // Example index
    printf("P/E Ratio: %.2f\n", calculate_pe(price, ep, index));

    // Example usage for finding duplicates
    int number[] = {3, 6, 2, 4, 3, 9, 11};
    int number_size = sizeof(number) / sizeof(number[0]);
    printf("Duplicates in the array:\n");
    find_duplicates(number, number_size);

    // Example usage for handling duplicates
    int no[] = {3, 6, 2, 4, 3, 6, 8, 9};
    int no_size = sizeof(no) / sizeof(no[0]);
    printf("Handling duplicates:\n");
    handle_duplicates(no, no_size);

    return 0;
}