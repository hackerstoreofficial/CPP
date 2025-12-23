#include <stdio.h>

// Function to calculate the theoretical address of an array element
unsigned int calculateTheoreticalAddress(int dimensions, int size[], int indices[]) {
    unsigned int address = 0;
    unsigned int multiplier = 1;

    for (int i = dimensions - 1; i >= 0; i--) {
        address += indices[i] * multiplier;
        multiplier *= size[i];
    }

    return address;
}

int main() {
    // Define the array dimensions and sizes
    int dimensions = 2;
    int size[] = {3, 4};  // Change the array size as needed

    // Initialize a 2D array
    int array[3][4];

    // Initialize variables for array indices
    int row, col;

    // Populate the array with values
    for (row = 0; row < size[0]; row++) {
        for (col = 0; col < size[1]; col++) {
            array[row][col] = row * 10 + col;
        }
    }

    // Print the array in row-major order
    printf("Row-Major Order:\n");
    for (row = 0; row < size[0]; row++) {
        for (col = 0; col < size[1]; col++) {
            printf("%3d ", array[row][col]);
        }
        printf("\n");
    }

    // Find the address of a specific element (e.g., array[1][2])
    int targetRow = 1;
    int targetCol = 2;
    int indices[] = {targetRow, targetCol};
    unsigned int theoreticalAddress = calculateTheoreticalAddress(dimensions, size, indices);


    printf("\nAddress of array[%d][%d] (Theoretical): %u\n", targetRow, targetCol, theoreticalAddress);

    // Find the actual address of the element
    unsigned int actualAddress = (unsigned int)&array[targetRow][targetCol];

    printf("Address of array[%d][%d] (Actual): %u\n", targetRow, targetCol, actualAddress);

    // Verify the addresses
    if (theoreticalAddress == actualAddress) {
        printf("\nVerification: Theoretical and Actual addresses match.\n");
    } else {
        printf("\nVerification: Theoretical and Actual addresses do not match.\n");
    }

    return 0;
}
