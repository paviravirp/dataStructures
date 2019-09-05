#include<iostream>
using namespace std;

void printTheArray(int arr[], int n) 
{ 
    for (int i = 0; i < n; i++) { 
        cout << arr[i] << " "; 
    } 
    cout << endl; 
}

void kAry(int n, int k, int arr[], int i) {
    if(n == i) {
        printTheArray(arr, n);
        return;
    }
    for(int j = 0; j <= k; j++) {
        arr[i] = j;
        kAry(n, k, arr, i + 1);
    }
}

int main() {
    int n, k;
    cout << "Enter length of each string: ";
    cin >> n;
    cout << "\n Enter the k: ";
    cin >> k;
    int arr[n];
    kAry(n, k, arr, 0);
}