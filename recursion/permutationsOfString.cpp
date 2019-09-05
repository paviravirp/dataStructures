#include<iostream>
#include <vector>
using namespace std;

vector<string> findPermutations(string str) {
    if(str.size() == 1) {
        return vector<string> { str };
    }
    vector<string> result;
    for(int i = 0; i < str.size(); i++) {
        char current = str[i];
        string remaining = str.substr(0, i) + str.substr(i+1);
        vector<string> permutations = findPermutations(remaining);
        for(auto &permutation : permutations) {
            result.push_back(current + permutation);
        }
    }
    return result;
}

int main() {
    string str;
    cout << "Enter the string: ";
    cin >> str;
    vector<string> result = findPermutations(str);
    for(auto &res : result) {
        cout << res << "\t";
    }
}