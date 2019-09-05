#include<iostream>
using namespace std;

void printTheArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
} 
void binary(int n, int arr[], int i)
{
    if(n == i) {
        printTheArray(arr, n);
        return;
    }
    else
    {
        arr[i] = 0;
        binary(n, arr, i + 1);
        arr[i] = 1;
        binary(n, arr, i + 1);
    }
}

int main() {
    int n;
    cout << "Enter number of bits: ";
    cin >> n;
    int arr[n];
    binary(n, arr, 0);
}