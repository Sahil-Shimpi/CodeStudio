// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381764

#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(string input) {
    int n = input.size();
    for (int i = 0; i < n; i++) 
    {
        for (int j = i; j < n; j++) 
        {
            for (int k = i; k < j + 1; k++) 
            {
                cout << input[k];
            }
            cout << endl;
        }
    }
}

int main() {
    string input;
    getline(cin, input);
    printSubstrings(input);
    return 0;
}
