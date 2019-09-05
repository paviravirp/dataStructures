#include <iostream>
using namespace std;

void towerOfHanoi(int num, char from, char to, char aux) {
    if(num == 1) {
        cout << "Move disk 1 from " << from << " to " << to << "\n";
        return;
    }
    towerOfHanoi(num - 1, from, aux, to);
    cout << "Move disk " << num << " from " << from << " to " << to << "\n";
    towerOfHanoi(num - 1, aux, to, from);
}

int main() {
    int num;
    char from, to, aux;
    cout << "Enter the number of disks: ";
    cin >> num;
    cout << "\n From: ";
    cin >> from;
    cout << "\n To: ";
    cin >> to;
    cout << "\n Aux: ";
    cin >> aux; 
    towerOfHanoi(num, from, to, aux);
}