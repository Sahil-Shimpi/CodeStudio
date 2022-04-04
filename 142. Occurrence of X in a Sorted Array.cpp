// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377947

int countOccurences(int arr[], int n, int X)
{
    int ans = 0;
    
    for(int i=0; i<n; i++)
    {
        if(arr[i] == X)
        {
            ans++;
        }
        else if(arr[i] > X)
        {
            break;
        }
    }
    
    return ans;
}
