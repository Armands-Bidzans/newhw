#include <iostream>
using namespace std;

double findMax(const int* arr, int size) {
    int maxVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

double findMin(const int* arr, int size) {
    int minVal = arr[0];
    for (int i = 1; i < size; ++i) {
        if (arr[i] < minVal) {
            minVal = arr[i];
        }
    }
    return minVal;
}

double findAvg(const int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; ++i) {
        sum += arr[i];
    }
    return (1.0 * sum) / size;
}

int main() {
    const int MAX_SIZE = 100;
    int arrA[MAX_SIZE]{}, arrB[MAX_SIZE]{};
    int sizeA{}, sizeB{};

    cout << "Enter the size of array A: ";
    cin >> sizeA;
    cout << "Enter elements of array A: ";
    for (int i = 0; i < sizeA; ++i) {
        cin >> arrA[i];
    }

    cout << "Enter the size of array B: ";
    cin >> sizeB;
    cout << "Enter elements of array B: ";
    for (int i = 0; i < sizeB; ++i) {
        cin >> arrB[i];
    }

    int choice{};
    do {
        cout << "Choose an option:\n1. Max\n2. Min\n3. Avg\n-1 to exit\nYour choice: ";
        cin >> choice;


        double resultA{}, resultB{};
        switch (choice) {
        case 1:
            resultA = findMax(arrA, sizeA);
            resultB = findMax(arrB, sizeB);
            cout << "Result (Max): Max of A = " << resultA << ", Max of B = " << resultB << endl;
            break;
        case 2:
            resultA = findMin(arrA, sizeA);
            resultB = findMin(arrB, sizeB);
            cout << "Result (Min): Min of A = " << resultA << ", Min of B = " << resultB << endl;
            break;
        case 3:
            resultA = findAvg(arrA, sizeA);
            resultB = findAvg(arrB, sizeB);
            cout << "Result (Avg): Avg of A = " << resultA << ", Avg of B = " << resultB << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    } while (choice != -1);

    return 0;
}
