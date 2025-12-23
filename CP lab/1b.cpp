#include <stdio.h>

int main() {
    int rows = 3;  // Number of rows
    int cols = 4;  // Number of columns

    int array[3][4];  // Define a 2D array

    // Initialize the array with some values
    int count = 1;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            array[i][j] = count++;
        }
    }

    printf("Array elements in row-major order:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);

            // Calculate and print the theoretical address
            int address = (i * cols + j) * sizeof(int);
            printf("(Theoretical Address: %p) ", (void*)&array[i][j]);
            printf("Actual Address: %p\n", (void*)&array[i][j]);
        }
        printf("\n");
    }

    return 0;
}
