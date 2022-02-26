// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381763?leftPanelTab=2

#include <iostream>
#include <cstring>
using namespace std;

int countWords(string input) {
    if (input.size() == 0)
        return 0;

    int count = 0;
    for (int i = 0; i < input.size(); i++) {
        if (input[i] == ' ')
            count++;
    }

    return count + 1;
}

int main() {
    string input;
    getline(cin, input);
    int output = countWords(input);
    cout << output << endl;
    return 0;
}
