// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380931?leftPanelTab=0

/*

    Time complexity: O(2^N)
    Space complexity: O(N^2)

    where 'N' is the number of letters in the string 'STR'.


*/

void subsequencesHelper(string s, int index, string temp, vector<string> &ans) {

    // Push the subsequence in ans
    if (index == s.length()) {

        // If the current subsequence is not empty
        if (temp.length() != 0) {
            ans.push_back(temp);
        }

        return;
    }
    // Not including the current letter in subsequence
    subsequencesHelper(s, index + 1, temp, ans);

    temp.push_back(s[index]);
    // Including the current letter in subsequence
    subsequencesHelper(s, index + 1, temp, ans);

}

vector<string> subsequences(string str) {

    // Stores length of input string
    int n = str.length();

    // To store all the subsequences of s
    vector<string> ans;

    string temp = "";

    // Finds all possible non empty subsequences of s
    subsequencesHelper(str, 0 , temp, ans);

    return ans;
}
