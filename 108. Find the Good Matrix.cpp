// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381912

/*
   Time Complexity: O(N * M)
   Space Complexity: O(N + M)

   where N and M denote the number of rows and columns in the array.
*/

vector<vector<int>> findGoodMatrix(vector<vector<int>> &arr) 
{
    int n = arr.size();
    int m = arr[0].size();

    // Create an array rows of size N and columns of size M with value 0 at each position
    vector<int> rows(n, 0);
    vector<int> columns(m, 0);

    // Traverse through the array ARR
    for (int index = 0; index < n; index++) 
    {
        for (int pos = 0; pos < m; pos++) 
        {
            // Check if ARR[index][pos] is equal to 0
            if (arr[index][pos] == 0) 
            {
                // Update rows[index] and columns[pos] with the value 1
                rows[index] = 1;
                columns[pos] = 1;
            }
        }
    }

    // Update the array ARR to convert the matrix into the Good matrix
    for (int index = 0; index < n; index++) 
    {
        for (int pos = 0; pos < m; pos++) 
        {
            // Check either rows[index] or columns[pos] is equal to 1
            if (rows[index] == 1 || columns[pos] == 1) 
            {
                arr[index][pos] = 0;
            }
        }
    }

    // Return the matrix ARR
    return arr;
}
