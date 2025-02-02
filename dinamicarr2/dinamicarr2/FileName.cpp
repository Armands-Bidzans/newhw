#include <iostream>
using namespace std;

void printMatrix(int** matrix, int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void addRow(int**& matrix, int& rows, int cols, int position, int* newRow) {
    int** newMatrix = new int*[rows + 1];
    for (int i = 0; i < position; ++i) {
        newMatrix[i] = matrix[i];
    }
    newMatrix[position] = newRow;
    for (int i = position; i < rows; ++i) {
        newMatrix[i + 1] = matrix[i];
    }
    delete[] matrix;
    matrix = newMatrix;
    ++rows;
}

void addColumn(int**& matrix, int rows, int& cols, int position, int* newCol) {
    for (int i = 0; i < rows; ++i) {
        int* newRow = new int[cols + 1];
        for (int j = 0; j < position; ++j) {
            newRow[j] = matrix[i][j];
        }
        newRow[position] = newCol[i];
        for (int j = position; j < cols; ++j) {
            newRow[j + 1] = matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i] = newRow;
    }
    ++cols;
}

void shiftRows(int** matrix, int rows, int cols, int shifts, bool direction) {
    shifts %= rows;
    int* temp;
    if (direction) {
        for (int i = 0; i < shifts; ++i) {
            temp = matrix[rows - 1];
            for (int j = rows - 1; j > 0; --j) {
                matrix[j] = matrix[j - 1];
            }
            matrix[0] = temp;
        }
    } else {
        for (int i = 0; i < shifts; ++i) {
            temp = matrix[0];
            for (int j = 0; j < rows - 1; ++j) {
                matrix[j] = matrix[j + 1];
            }
            matrix[rows - 1] = temp;
        }
    }
}

void shiftColumns(int** matrix, int rows, int cols, int shifts, bool direction) {
    shifts %= cols;
    int temp;
    if (direction) {
        for (int i = 0; i < shifts; ++i) {
            for (int j = 0; j < rows; ++j) {
                temp = matrix[j][cols - 1];
                for (int k = cols - 1; k > 0; --k) {
                    matrix[j][k] = matrix[j][k - 1];
                }
                matrix[j][0] = temp;
            }
        }
    } else {
        for (int i = 0; i < shifts; ++i) {
            for (int j = 0; j < rows; ++j) {
                temp = matrix[j][0];
                for (int k = 0; k < cols - 1; ++k) {
                    matrix[j][k] = matrix[j][k + 1];
                }
                matrix[j][cols - 1] = temp;
            }
        }
    }
}

int main() {
    int rows, cols;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> rows >> cols;

    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Enter matrix elements:" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    cout << "Initial matrix:" << endl;
    printMatrix(matrix, rows, cols);

    int choice;
    cout << "Choose an operation:\n1. Add row\n2. Add column\n3. Shift rows\n4. Shift columns\n";
    cin >> choice;

    if (choice == 1) {
        int position;
        cout << "Enter position to add row (0 to " << rows << "): ";
        cin >> position;
        int* newRow = new int[cols];
        cout << "Enter new row elements: ";
        for (int i = 0; i < cols; ++i) {
            cin >> newRow[i];
        }
        addRow(matrix, rows, cols, position, newRow);
        cout << "Matrix after adding row:" << endl;
        printMatrix(matrix, rows, cols);
    } else if (choice == 2) {
        int position;
        cout << "Enter position to add column (0 to " << cols << "): ";
        cin >> position;
        int* newCol = new int[rows];
        cout << "Enter new column elements: ";
        for (int i = 0; i < rows; ++i) {
            cin >> newCol[i];
        }
        addColumn(matrix, rows, cols, position, newCol);
        cout << "Matrix after adding column:" << endl;
        printMatrix(matrix, rows, cols);
    } else if (choice == 3) {
        int shifts;
        bool direction;
        cout << "Enter number of shifts: ";
        cin >> shifts;
        cout << "Enter direction (0 for down, 1 for up): ";
        cin >> direction;
        shiftRows(matrix, rows, cols, shifts, direction);
        cout << "Matrix after shifting rows:" << endl;
        printMatrix(matrix, rows, cols);
    } else if (choice == 4) {
        int shifts;
        bool direction;
        cout << "Enter number of shifts: ";
        cin >> shifts;
        cout << "Enter direction (0 for right, 1 for left): ";
        cin >> direction;
        shiftColumns(matrix, rows, cols, shifts, direction);
        cout << "Matrix after shifting columns:" << endl;
        printMatrix(matrix, rows, cols);
    } else {
        cout << "Invalid choice." << endl;
    }

    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}