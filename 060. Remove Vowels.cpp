// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377977

/*
    Time Complexity: O(N)
    Space complexity: O(N)

    Where N is the length of the string.
*/

string removeVowels(string inputString)
{
    string result;

    for (int i = 0; i < inputString.length(); i++)
    {
        char curr = inputString[i];

        if (curr != 'a' && curr != 'e' && curr != 'i' && curr != 'o' && curr != 'u' && curr != 'A' && curr != 'E' && curr != 'I' && curr != 'O' && curr != 'U')
        {
            result.push_back(curr);
        }
    }

    return result;
}

