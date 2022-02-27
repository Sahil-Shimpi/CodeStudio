// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381766?leftPanelTab=2

#include <iostream>
#include <cstring>
using namespace std;

string removeConsecutiveDuplicates(string input)
{
    int n = input.size();
    char arr[n];
    int ptr = 0;
    arr[0] = input[0];
    string s = "";
    for(int i=1; i<n; i++)
    {
        if(input[i] != arr[ptr])
        {
            arr[ptr+1] = input[i];
            ptr++;
        }
    }
    for (int i=0; i<=ptr; i++) 
    {
        s = s + arr[i];
    }
    return s;
}

int main()
{
    string str;
    cin >> str;
    string ans = removeConsecutiveDuplicates(str);
    cout << ans << endl;
}
