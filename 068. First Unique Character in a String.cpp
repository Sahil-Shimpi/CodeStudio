// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382157

#include <unordered_map>

char findNonRepeating(string str) 
{
    int n = str.length();
    unordered_map <char, int> freq;
    for(int i=0; i<n; i++)
    {
        char temp = str[i];
        freq[temp]++;
    }
    for(int i=0; i<n; i++)
    {
        if(freq[str[i]] == 1)
        {
            return str[i];
        }
    }
    return '#';
}
