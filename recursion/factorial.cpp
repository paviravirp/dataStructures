#include <iostream>
using namespace std;

int factIteration(int num) {
    int factorial = 1;
    while(num > 1) {
        factorial *= num--;
    }
    return factorial;
}

int fact(int num) {
    if(num <= 1) return 1;
    return num * fact(num - 1);
}

int main() {
    int num;
    cout << "Enter the number: ";
    cin >> num;
    cout << fact(num) << "\n";
}