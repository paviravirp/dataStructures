#include <iostream>
using namespace std;

bool checkIfSorted(int array[], int n) {
    if(n == 1) return true;
    return (array[n-1] < array[n-2]) ? false : checkIfSorted(array, n-1);
}

int main() {
    int sizeOfArray;
    cout << "Enter the size of array: ";
    cin >> sizeOfArray;
    int array[sizeOfArray];
    cout << "Enter the array elements: ";
    for (int i = 0; i < sizeOfArray; i++)
    {
        cin >> array[i];
    }
    cout << checkIfSorted(array, sizeOfArray) << "\n";
}