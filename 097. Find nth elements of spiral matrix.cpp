// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381902

int findKthElement(vector<vector<int>> matrix, int k) 
{
     int i;
     int r = 0;
     int rows = matrix.size();
     int c = 0;
     int cols = matrix[0].size();
 
    /*  
        r - starting row index,
        rows - ending row index,
        c - starting column index,
        cols - ending column index,
        i - iterator.
    */
 
    // Make vector to store the path.
    vector<int> path;

    while (r < rows && c < cols) 
    {
        // Push the first row from the remaining rows .
        for (i = c; i < cols; ++i) 
        {
            path.push_back(matrix[r][i]);
        }
        r = r + 1;
 
        // Push the last column from the remaining columns.
        for (i = r; i < rows; ++i) 
        {
            path.push_back(matrix[i][cols - 1]);
        }
        cols = cols - 1;
 
        // Push the last row from the remaining rows. 
        if (r < rows)
        {
            for (i = cols - 1; i >= c; --i) 
            {
                path.push_back(matrix[rows - 1][i]);
            }
            rows = rows - 1;
        }
 
        // Push the first column from the remaining columns. 
        if (c < cols) 
        {
            for (i = rows - 1; i >= r; --i) 
            {
                path.push_back(matrix[i][c]);
            }
            c = c + 1;
        }
    }

    return path[k-1];
}
