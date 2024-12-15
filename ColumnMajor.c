#include <stdio.h>

int main() {
    // Define a 2x3 matrix
    int matrix[2][3] = {{1, 2, 3}, {4, 5, 6}};
    
    // Printing the matrix using column-major order
    printf("Matrix in Column-Major Order:\n");
    for (int j = 0; j < 3; j++) {   // Loop through columns first
        for (int i = 0; i < 2; i++) {   // Then loop through rows
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    // Accessing the elements of the matrix using column-major memory layout
    printf("\nAccessing elements as if in memory:\n");
    for (int i = 0; i < 6; i++) {
        printf("%d ", *((int*)matrix + i));  // Accessing in a 1D fashion (column-major)
    }
    
    return 0;
}
