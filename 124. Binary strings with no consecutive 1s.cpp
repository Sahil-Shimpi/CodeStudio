// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380926?leftPanelTab=1

/*
    Time Complexity: O(2 ^ N)
    Space Complexity: O(N)

    Where 'N' is the length of the string to be created.
*/

void generateStringHelper(int k, string &str, int n, vector<string> &ans) 
{

    // Terminate binary string ans push in answer.
    if (n == k) 
    {
        ans.push_back(str);

        return;
    }

    /*
        If previous character is '1' then we put 
        only 0 at end of string.
        Example str = "01" then new string will be "010".
    */
    if (str[n - 1] == '1') 
    {
        str[n] = '0';
        generateStringHelper(k, str, n + 1, ans);
    }

    /*
        If previous character is '0' then we put 
        both '1' and '0' at end of string.
        Example str = "00" then new string is "001" and "000".
    */
    if (str[n - 1] == '0') 
    {
        str[n] = '0';
        generateStringHelper(k, str, n + 1, ans);
        str[n] = '1';
        generateStringHelper(k, str, n + 1, ans);
    }
}

vector<string> generateString(int k) 
{
    vector<string> ans;

    // If K=0 no binary strings are possible, hence we return empty array.
    if (k == 0) 
    {
        return ans;
    }

    // A string with K elements.
    string str(k, '0');

    // First character 0.
    str[0] = '0';
    generateStringHelper(k, str, 1, ans);

    // First character 1.
    str[0] = '1';
    generateStringHelper(k, str, 1, ans);

    sort(ans.begin(), ans.end());

    return ans;
}
