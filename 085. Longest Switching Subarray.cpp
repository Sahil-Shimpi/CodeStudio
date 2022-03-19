// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376576

#include <bits/stdc++.h>

int switchingSubarray(vector<int> &arr, int n) 
{
    int ans = 2;
    int cnt = 2;
    if(n == 1)
    {
        return 1;
    }
    else if(n == 2)
    {
        return 2;
    }
    else
    {
        int s = 0;
        int e = 2;
        while(e<n)
        {
            if(arr[s] != arr[e])
            {
                s++;
                e++;
                cnt = 2;
            }
            else
            {
                cnt++;
                ans = max(ans, cnt);
                s++;
                e++;
            }
        }
    }
    return ans;
}
