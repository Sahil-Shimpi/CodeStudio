// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381890

int findSecondLargest(int n, vector<int> &arr)
{
    sort(arr.begin(), arr.end(), greater<int>());
    int ans = -1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] != arr[0])
        {
            ans = arr[i];
            break;
        }
    }
    return ans;
}
