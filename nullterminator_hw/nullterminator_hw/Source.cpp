#include <iostream>
using namespace std;
const int MAX_SIZE = 100;
int main() {
    char input[MAX_SIZE]{};
    cout << "Enter a string (up to " << MAX_SIZE - 1 << " characters): ";
    cin >> input;

    int occupied = 0;
    while (input[occupied] != '\0') {
        ++occupied;
    }
    int free = MAX_SIZE - occupied - 1;

    cout << "Occupied elements: " << occupied << endl;
    cout << "Free elements: " << free << endl;

    int m, n;
    cout << "Enter the range m and n (0-based indices): ";
    cin >> m >> n;

    if (m < 0 || n >= occupied || m > n) {
        cout << "Invalid range!" << endl;
        return 1;
    }
    char segment[MAX_SIZE]{};
    int segmentLength = 0;
    for (int i = m; i <= n; ++i) {
        segment[segmentLength++] = input[i];
    }
    segment[segmentLength] = '\0';
    cout << "Segment from m to n: " << segment << endl;
    return 0;
}