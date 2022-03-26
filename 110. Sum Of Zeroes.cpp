// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381914?leftPanelTab=0

/*
    Time Complexity O(N*M)
    Space Complexity: O(1)

    where N and M are the dimensions of the input array.
*/

int coverageOfMatrix(vector<vector<int>> &mat) {
    int n = mat.size();
    int m = mat[0].size();

    // This variable stores our answer.
    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            
            // If current element is 1 then we do not need to check for neighbours
            if(mat[i][j]==1){
                continue;
            }
            // If left neighbour is 1: increment ans by 1
            if(i-1 >= 0){
                ans += mat[i-1][j];
            }
            // If top neighbour is 1: increment ans by 1
            if(j+1 < m){
                ans += mat[i][j+1];
            }
            // If right neighbour is 1: increment ans by 1
            if(i+1 < n){
                ans += mat[i+1][j];
            }
            // If bottom neighbour is 1: increment ans by 1
            if(j-1 >= 0){
                ans += mat[i][j-1];
            }
        }
    }

    // Return the final answer.
    return ans;
}
