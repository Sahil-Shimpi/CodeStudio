// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381903

vector<int> rotateMatRight(vector<vector<int>> mat, int n, int m, int k) 
{
    k = k % m;
    vector <int> ans;
    if(k == 0)
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            for(int j=m-k; j<m; j++)
            {
                ans.push_back(mat[i][j]);
            }
            for(int j=0; j<m-k; j++)
            {
                ans.push_back(mat[i][j]);
            }
        }
        return ans;
    }
}
