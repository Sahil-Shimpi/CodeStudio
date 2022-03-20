// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376577

#include <bits/stdc++.h>

vector<int> findEquilibriumIndices(vector<int> &seq) 
{
    vector <int> ans;
    int sum = accumulate(seq.begin(),seq.end(),0);
    if(sum == seq[0])
    {
        ans.push_back(0);
    }
    int curr_sum = seq[0];
    for(int i=1; i<seq.size(); i++)
    {
        if(sum - seq[i] == 2 * curr_sum)
        {
            ans.push_back(i);
        }
        curr_sum += seq[i];
    }
    return ans;
}
