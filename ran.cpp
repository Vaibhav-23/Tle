#include <iostream>

void printSquare(int n) {
    int matrix[10][10];

    int value = 1;
    int startRow = 0, startCol = 0;
    int endRow = 9, endCol = 9;

    while (startRow <= endRow && startCol <= endCol) {
        // Fill the outer square with the current value
        for (int i = startCol; i <= endCol; ++i) {
            matrix[startRow][i] = value;
        }
        ++startRow;

        for (int i = startRow; i <= endRow; ++i) {
            matrix[i][endCol] = value;
        }
        --endCol;

        if (startRow <= endRow) {
            for (int i = endCol; i >= startCol; --i) {
                matrix[endRow][i] = value;
            }
            --endRow;
        }

        if (startCol <= endCol) {
            for (int i = endRow; i >= startRow; --i) {
                matrix[i][startCol] = value;
            }
            ++startCol;
        }

        ++value;
    }

    // Print the matrix
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            std::cout << matrix[i][j];
        }
        std::cout << std::endl;
    }
}

int main() {
    printSquare(10);

    return 0;
}
