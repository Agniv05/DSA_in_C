#include <stdio.h>

int main() {
    // Define a 2x3 matrix
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // Printing the matrix using row-major order
    printf("Matrix in Row-Major Order:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Accessing the elements of the matrix using row-major memory layout
    printf("\nAccessing elements as if in memory:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *((int*)matrix + i));  // Accessing in a 1D fashion (row-major)
    }
    
    return 0;
}
