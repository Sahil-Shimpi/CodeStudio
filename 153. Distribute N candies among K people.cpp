// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377962

/*
    Time Complexity: O(log(N) + K)
    Space Complexity:O(K)
    
    Where N is the total number of candies and K is the total number of his friends .
*/

#include<climits>
vector < int > candies(int n, int k) 
{

    // Stores the number of candies
    vector < int > ans(k);
    
    // Initialise low and high
    int low = 0, high = INT_MAX;
    
    // Binary search
    while (low <= high) 
    {
        int mid = low + (high - low) / 2;
        if (1ll * mid * (mid + 1) / 2 > n) 
        {
            high = mid - 1;
        } 
        else 
        {
            low = mid + 1;
        }
    }
    int val = (low - 1) / k;
    
    for (int i = 0; i < k; i++) 
    {
        ans[i] = ((val - 1) * val / 2) * k + val * (i + 1);
        n = n - ans[i];
    }
    int x = val * k;
    for (int i = 0; i < k; i++) 
    {
        if (n <= 0)
        {
            break;
        }
        ans[i] = ans[i] + min(n, ++x);
        n = n - min(n, x);
    }
    return ans;
}
