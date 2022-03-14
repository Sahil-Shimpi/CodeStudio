// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377990

/*
	Time complexity: O(N * length(Pattern))
	Space Complexity: O(length(Pattern))
	
	Where N is the number of words in the list.
*/

#include <unordered_map>

string generateHash(string &str)
{	
	// Maintain a HashMap
    unordered_map<char, int> mp;
	
	// Create a varible hash, which will store the hash for a given word
    string hash;

    int counter = 1;

    for (int i = 0; i < str.length(); ++i)
    {
        char ch = str[i];

        if (mp.find(ch) == mp.end())
        {
            // Found a distinct character
            mp[ch] = counter++;
        }

        hash = hash + to_string(mp[ch]);
    }
	
	// Return the variable hash
    return hash;
}

vector<string> matchSpecificPattern(vector<string> words, int n, string pattern)
{
    // Create an array to store all valid words
	vector<string> ans;
	
	string hashPattern = generateHash(pattern);

    // Iterate over all the words
    for (int i = 0; i < n; i++)
    {
        string word = words[i];

        if (word.length() == pattern.length())
        {
            string hashWord = generateHash(word);

            if (hashWord == hashPattern)
            {
                // Word matches the pattern
                ans.push_back(word);
            }
        }
    }
    
	// Return the array answer
    return ans;
}
