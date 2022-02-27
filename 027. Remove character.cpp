// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381769?leftPanelTab=1

#include <iostream>
#include <cstring>
using namespace std;

string removeAllOccurrencesOfChar(string input, char c) 
{
    int n = input.size();
    string ans = "";
    for(int i=0; i<n; i++)
    {
        if(input[i] != c)
        {
            ans += input[i];
        }
    }
    return ans;
}

int main() {
    string input;
    char c;
    cin >> input >> c;
    string output = removeAllOccurrencesOfChar(input, c);
    cout << output << endl;
    return 0;
}
