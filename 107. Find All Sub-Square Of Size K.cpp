// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381911

/*
    Time Complexity O(N^2)
    Space Complexity: O(N^2)

    where N is the number of rows in the square matrix ARR.
*/

vector<vector<int>> sumOfKxKMatrices(vector<vector<int>> &arr, int k) {
    int n = arr.size();

    // This vector stores our answer.
    vector<vector<int>> ans(n - k + 1, vector<int>(n - k + 1));
    // This vector stores our prefix sum of elements.
    vector<vector<int>> prefix(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            // Calculating the prefix sums.
            prefix[i][j] = prefix[i - 1][j] + prefix[i][j - 1] - prefix[i - 1][j - 1] + arr[i - 1][j - 1];
        }
    }

    for (int i = 1; i <= n - k + 1; i++) {
        for (int j = 1; j <= n - k + 1; j++) {
            // Using the formula as described in the explanation.
            ans[i - 1][j - 1] = prefix[i + k - 1][j + k - 1] - prefix[i - 1][j + k - 1] - prefix[i + k - 1][j - 1] + prefix[i - 1][j - 1];
        }
    }

    // Return the final answer.
    return ans;
}
