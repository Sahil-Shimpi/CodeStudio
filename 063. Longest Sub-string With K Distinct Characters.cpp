// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377986

/*
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where N is the size of the string.
*/

#include <vector>

// Returns the number of distinct characters in the array 'freq'.
int countDistinct(vector<int>& freq) {
    int distinct = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i]) {
            distinct++;
        }
    }

    return distinct;
}

int getLengthofLongestSubstring(string s, int k) {
    int longestLength = 0;
    int n = s.size();

    vector<int> freq(26, 0);

    // Starting index of the window.
    int start = 0;

    // Traverse for ending index of the window.
    for (int i = 0; i < n; i++) {
        freq[s[i] - 'a']++;

        while (countDistinct(freq) > k) {
            freq[s[start] - 'a']--;
            start++;
        }

        longestLength = max(longestLength, i - start + 1);
    }

    return longestLength;
}
