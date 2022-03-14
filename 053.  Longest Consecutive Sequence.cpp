// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381889

#include <algorithm>

int lengthOfLongestConsecutiveSequence(vector<int> &arr, int n) 
{
    sort(arr.begin(), arr.end());
    int mx = 1;
    int ans = 1;
    for(int i=1; i<n; i++)
    {
        if(arr[i] == arr[i-1] + 1)
        {
            ans++;
            mx = max(ans, mx);
        }
        else if(arr[i] == arr[i-1])
        {
            continue;
        }
        else
        {
            ans = 1;
        }
    }
    return mx;
}
