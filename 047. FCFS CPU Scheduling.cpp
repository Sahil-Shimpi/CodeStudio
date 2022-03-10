// Problem: https://www.codingninjas.com/codestudio/guided-paths/operating-system-track/content/119091/offering/1404612

vector<vector<int>> findScheduling(int n, vector<int> &burstTime) 
{
    vector<vector<int>> ans;
    vector<int> inner;
    int presum = 0;
    
    if(n==1)
    {
        ans = {{0},{burstTime[n-1]}};
    }
    else
    {
        inner[0] = 0;
        for(int i=0; i<n-1; i++)
        {
            presum += burstTime[i];
            inner.push_back(presum);
        }
        ans.push_back(inner);
        for(int i=0; i<n-1; i++)
        {
            inner[i] = inner[i+1];
        }
        inner[n-1] = presum + burstTime[n-1];
        ans.push_back(inner);
    }
    return ans;
  
}
