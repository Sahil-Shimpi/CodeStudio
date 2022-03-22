// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381899

bool isMatrixSymmetric(vector<vector<int>> matrix)
{
    int n = matrix.size();
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(matrix[i][j] != matrix[j][i])
            {
                return false;
            }
        }
    }
    return true;
}
