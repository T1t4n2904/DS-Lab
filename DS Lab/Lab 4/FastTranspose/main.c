#include <stdio.h>
#include <stdlib.h>

// Define a structure to represent a sparse matrix element
struct SparseMatrixElement {
    int row;
    int col;
    int value;
};

// Function to find the transpose of a sparse matrix
void fastTranspose(struct SparseMatrixElement* inputMatrix, int numRows, int numCols, int numNonZero,
                   struct SparseMatrixElement* outputMatrix) {
    int* rowTerms = (int*)malloc(numCols * sizeof(int));
    int* startingPos = (int*)malloc(numCols * sizeof(int));

    if (!rowTerms || !startingPos) {
        printf("Memory allocation error.\n");
        return;
    }

    // Initialize rowTerms and startingPos arrays
    for (int i = 0; i < numCols; i++) {
        rowTerms[i] = 0;
        startingPos[i] = 0;
    }

    // Count the number of non-zero elements in each column
    for (int i = 0; i < numNonZero; i++) {
        rowTerms[inputMatrix[i].col]++;
    }

    // Compute the starting position of each column in the transpose matrix
    startingPos[0] = 0;
    for (int i = 1; i < numCols; i++) {
        startingPos[i] = startingPos[i - 1] + rowTerms[i - 1];
    }

    // Fill the transpose matrix
    for (int i = 0; i < numNonZero; i++) {
        int j = startingPos[inputMatrix[i].col];
        outputMatrix[j].row = inputMatrix[i].col;
        outputMatrix[j].col = inputMatrix[i].row;
        outputMatrix[j].value = inputMatrix[i].value;
        startingPos[inputMatrix[i].col]++;
    }

    free(rowTerms);
    free(startingPos);
}

// Function to display a sparse matrix
void displayMatrix(struct SparseMatrixElement* matrix, int numRows, int numCols, int numNonZero) {
    printf("Sparse Matrix:\n");
    for (int i = 0; i < numNonZero; i++) {
        printf("%d %d %d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

int main() {
    int numRows = 4;
    int numCols = 5;
    int numNonZero = 6;

    // Define the input sparse matrix
    struct SparseMatrixElement inputMatrix[] = {
        {0, 0, 1},
        {1, 1, 2},
        {2, 2, 3},
        {3, 2, 4},
        {1, 3, 5},
        {2, 4, 6}
    };

    // Allocate memory for the output matrix
    struct SparseMatrixElement* outputMatrix = (struct SparseMatrixElement*)malloc(numNonZero * sizeof(struct SparseMatrixElement));
    if (!outputMatrix) {
        printf("Memory allocation error.\n");
        return 1;
    }

    // Find the transpose of the input matrix
    fastTranspose(inputMatrix, numRows, numCols, numNonZero, outputMatrix);

    // Display the input and output matrices
    printf("Original Matrix:\n");
    displayMatrix(inputMatrix, numRows, numCols, numNonZero);

    printf("Transpose Matrix:\n");
    displayMatrix(outputMatrix, numCols, numRows, numNonZero);

    // Free allocated memory
    free(outputMatrix);

    return 0;
}

