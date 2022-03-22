// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381898

pair<int, int> search(vector<vector<int>> matrix, int x)
{
    pair<int, int> ans;
    for(int i=0; i<matrix.size(); i++)
    {
        for(int j=0; j<matrix[i].size(); j++)
        {
            if(matrix[i][j] == x)
            {
                ans.first = i;
                ans.second = j;
                return ans;
            }
        }
    }
    return {-1, -1};
}
