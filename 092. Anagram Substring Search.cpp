// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376583

/*
    Time complexity: O(N)
    Space complexity: O(K)

    Where 'N' is number of characters,
    in given text 'STR' and 'K' is number of elements,
    in 'ANSWER' sequence.
*/

vector<int> findAnagramsIndices(string str, string ptn, int n, int m)
{

    // Array to store frequeny of character.
    vector<int> strMap(26, 0);
    vector<int> ptnMap(26, 0);

    vector<int> answer;

    /*
       If 'A' character in 'st'
       then we will increase value of 'strMap[0]'
       and character is 'B' then value of 'strMpa[1]' will increase.
    */
    for (int i = 0; i < m; i++) 
    {
        ptnMap[ptn[i] - 65] += 1;

        strMap[str[i] - 65] += 1;
    }

    // To check starting substring is anagram or not.
    bool flag = true;
    for (int j = 0; j < 26; j++) 
    {
        if (strMap[j] != ptnMap[j]) 
        {
            flag = false;
            break;
        }
    }

    if (flag) 
    {
        answer.push_back(0);
    }

    for (int i = m; i < n; i++) 
    {
        strMap[str[i] - 65] += 1;

        strMap[str[i - m] - 65] -= 1;

        bool flag = true;
        for (int j = 0; j < 26; j++) 
        {
            if (strMap[j] != ptnMap[j]) 
            {
                flag = false;
                break;
            }
        }

        // If index 'i-m+1' to 'i' substring is anagram with 'ptr'.
        if (flag) 
        {
            answer.push_back(i - m + 1);
        }
    }

    return answer;
}
