// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381907

/*
    Time Complexity O(N*M)
    Space Complexity: O(N*M)

    where N and M are the dimensions of the input array.
*/

vector<int> rowWaveForm(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    // This vector stores our answer.
    vector<int> ans(n*m);

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (i & 1) {
                // If the current row is odd then we need to sweep it right to left.
                ans[i * m + j] = mat[i][m - 1 - j];
            }
            else {
                // If the current row is even then we need to sweep it left to right.
                ans[i * m + j] = mat[i][j];
            }
        }
    }

    // Return the final answer.
    return ans;
}
