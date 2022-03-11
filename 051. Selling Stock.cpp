// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381887

#include <vector>

long getMaximumProfit(long *values, int n)
{
    vector<long> diff; // An array of differences
    long profit = 0;
    
    for(int i=0; i<n-1; i++)
    {
        long temp = values[i+1] - values[i];
        diff.push_back(temp);
    }
    
    for(int i=0; i<diff.size(); i++)
    {
        if(diff[i] > 0)
        {
            profit += diff[i];
        }
    }
    
    return profit;
}
