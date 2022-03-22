// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381901?leftPanelTab=0

/*
    Time Complexity : O(N * M)
    Space Complexity : O(1)

    Where N is the number of rows in the matrix,
    and M is the number of columns in the matrix.
*/

vector<int> spiralPathMatrix(vector<vector<int> > matrix, int n, int m)
{
     int i;
     int r = 0;
     int rows = n;
     int c = 0;
     int cols = m;
 
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

    return path;
}
