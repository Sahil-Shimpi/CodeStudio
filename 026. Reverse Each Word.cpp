// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118818/offering/1381769

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

string reverseEachWord(string input)
{
    int previous = -1;
    input += " ";
    int n = input.size();
    for (int i = 0; i < n; i++)
    {
        if (input[i] == ' ')
        {
            // reverse the current word
            int st = previous + 1, end = i - 1;
            while (st < end)
            {
                swap(input[st], input[end]);
                st++;
                end--;
            }
            previous = i;
        }
    }
    return input;
}

int main()
{

    string str;
    getline(cin, str);
    string ans = reverseEachWord(str);
    cout << ans << endl;
    ;
}
