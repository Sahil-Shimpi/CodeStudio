// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382157

/*
	Time complexity: O(N)
	Space complexity: O(1)

	Where N is the length of the string 
*/

// Calculate count of characters in the string str
vector<int> getcharCount(string str) 
{
    vector<int> charCount(257,0);

    for (int i = 0; i < str.size(); i++) 
    {
        charCount[str[i]-'a']++;
    }

    return charCount;
}

// Returns first non-repeating character in a string, else returns '#'
char findNonRepeating(string str) 
{
    vector<int> charCount;
    charCount = getcharCount(str);

    for (int i = 0; i < str.size(); i++) 
    {
        if (charCount[str[i]-'a'] == 1) 
        {
            return str[i];
        }
    }

    return '#';
}
