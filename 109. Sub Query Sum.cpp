// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381913?leftPanelTab=1

/*
   Time Complexity: O(N * M + K)
   Space Complexity: O(N * M + K)

   where N and M denote the number of rows and columns in the array ARR and K denote the number of queries.
*/

vector<int> findSubmatrixSum(vector<vector<int>> &arr, vector<vector<int>> &queries) 
{
    int n = arr.size();
    int m = arr[0].size();
    int k = queries.size();

    // Create an array answer to store the sum of the submatrix for each query 
    vector<int> answer(k);

    // Create an array auxiliary of size N and columns of size M
    vector<vector<int>> auxiliary(n);

    for (int index = 0; index < n; index++) 
    {
        auxiliary[index].resize(m);

        for (int pos = 0; pos < m; pos++) 
        {
            auxiliary[index][pos] = 0;
        }
    }

    // Copy the first row of ARR into auxiliary
    for (int index = 0; index < m; index++)
    {
        auxiliary[0][index] = arr[0][index];
    }
        
    // Update the matrix auxiliary with column wise sum
    for (int index = 1; index < n; index++)
    {
        for (int pos = 0; pos < m; pos++)
        {
            auxiliary[index][pos] = arr[index][pos] + auxiliary[index - 1][pos];
        }
    }
        
    // Update the matrix auxiliary with row wise sum
    for (int index = 0; index < n; index++) 
    {
        for (int pos = 1; pos < m; pos++) 
        {
            auxiliary[index][pos] += auxiliary[index][pos - 1];
        }
    }

    // Traverse through each query
    for (int queryNumber = 0; queryNumber < k; queryNumber++) 
    {
        int topRow = queries[queryNumber][0];
        int topColumn = queries[queryNumber][1];
        int bottomRow = queries[queryNumber][2];
        int bottomColumn = queries[queryNumber][3];

        // The variable sum stores the sum of the submatrix of the current query
        int sum = auxiliary[bottomRow][bottomColumn];

        // Check if topRow is more than 0
        if (topRow > 0) 
        {
            sum = sum - auxiliary[topRow - 1][bottomColumn];
        }

        // Check if topColumn is more than 0
        if (topColumn > 0) 
        {
            sum = sum - auxiliary[bottomRow][topColumn - 1];
        }

        // Check if topRow and topColumn are more than 0
        if (topRow > 0 && topColumn > 0) 
        {
            sum = sum + auxiliary[topRow - 1][topColumn - 1];
        }

        // Insert sum in the array answer
        answer[queryNumber] = sum;
    }

    // Return the array answer
    return answer;
}
