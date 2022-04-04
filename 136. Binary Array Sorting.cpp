// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382143

vector<int> sortBinaryArray(vector<int> arr, int n)
{
    vector <int> ans;
    int c0 = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            c0++;
        }
    }
    
    for(int i=0; i<c0; i++)
    {
        ans.push_back(0);
    }
    
    for(int i=c0; i<n; i++)
    {
        ans.push_back(1);
    }
    
    return ans;
}
