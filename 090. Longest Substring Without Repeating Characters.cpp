// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376581

/*

    Time Complexity: O(L).
    Space Complexity: O(L).
    
    Where L is the length of the input string.

*/

#include <unordered_map>

int lengthOfLongestSubstring(string &s) 
{
    // Declaring an unordered map to store the last occurence of the character.
    unordered_map < char, int > mp;

    int start = 0, end = 0;

    // Declaring maxlen which will store the length of the longest substring without repeating characters.
    int maxLen = 0;

    while (end < s.size()) 
    {
        char c = s[end];

        if (mp.find(c) != mp.end()) 
        {
            start = max(start, mp[c] + 1);
        }

        // Updating maxLen.
        maxLen = max(maxLen, end - start + 1);

        // Storing the current occurence of character in map.
        mp[c] = end;
        end++;
    }
    // Return maxlen which is storing the length of the longest substring without repeating characters.
    return maxLen;
}
