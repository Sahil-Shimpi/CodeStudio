// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376582?leftPanelTab=1

/*
    Time complexity: O(n)
    Space complexity: O(c)
    
    Where ‘n’ is the number of fruit trees and 'c' is constant. 
*/

#include <unordered_map>

int findMaxFruits(string &str, int n) 
{
    // Start and End of sliding window
    int start = 0, end = 0;
    int maxFruits = 0;
    
    // Contain unique elements in the current window mapped with their frequency in that window
    unordered_map<char, int> characters;

    // Finding maximum length of substring having atmost 2 distinct characters.
    while(end < n) 
    {
        if(characters.count(str[end]) or characters.size() < 2) 
        {
            characters[str[end]]++;
            end++;
            maxFruits = max(maxFruits, end - start);
        }
        else 
        {
            characters[str[start]]--;
            if(characters[str[start]] == 0) 
            {
                characters.erase(str[start]);
            }
            start++;
        }
    }

    return maxFruits;
}
