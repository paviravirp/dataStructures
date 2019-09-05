#include<iostream>
using namespace std;

void regularExpression(string input, string result, int i) {
    if(i == input.size()) {
        cout << result << "\n";
        return;
    }
    if(input[i] == '?') {
        result[i] = '0';
        regularExpression(input, result, i + 1);
        result[i] = '1';
        regularExpression(input, result, i + 1);
    } else {
        result[i] = input[i];
        regularExpression(input, result, i + 1);
    }
}

int main() {
    string input;
    cout << "Enter input test string ";
    cin >> input;
    string result = input;
    regularExpression(input, result, 1);
}