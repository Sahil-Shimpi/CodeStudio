// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381891

#include <bits/stdc++.h> 

int calculateMinPatforms(int at[], int dt[], int n) 
{
    vector <pair<int, int>> arr;
    
    for(int i=0; i<n; i++)
    {
        pair<int, int> temp;
        temp.first = at[i];
        temp.second = -1;
        arr.push_back(temp);
    }
    
    for(int i=0; i<n; i++)
    {
        pair<int, int> temp;
        temp.first = dt[i];
        temp.second = 1;
        arr.push_back(temp);
    }
    
    int ans = 0;
    int mx = 1;
    sort(arr.begin(), arr.end());
    for(int i=0; i<2*n; i++)
    {
        if(arr[i].second == -1)
        {
            ans++;
            mx = max(ans, mx);
        }
        else if(arr[i].second == 1)
        {
            ans--;
        }
    }
    return mx;
}
