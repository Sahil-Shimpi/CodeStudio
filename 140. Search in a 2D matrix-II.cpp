// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377946?leftPanelTab=0

bool findInMatrix(int x, vector<vector<int>> &arr)
{
    int r = arr.size();
    int c = arr[0].size();
    
    int rp = 0;
    int cp = c - 1;
    
    while(rp < r && cp > -1)
    {
        if(x == arr[rp][cp])
        {
            return true;
        }
        
        if(arr[rp][cp] < x)
        {
            rp++;
        }
        else
        {
            cp--;
        }
    }
    
    return false;
}
