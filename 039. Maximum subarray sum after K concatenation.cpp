// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381873

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of vector/list 'ARR'.
*/


long long kadane(vector<int> &arr, int n, int k)
{
    long long maxSum = -1e15;
    long long curSum = 0; 
  
    for (int i = 0; i < n * k; i++) 
    { 
        curSum += arr[i % n];   
        maxSum = max(maxSum, curSum);  
        if (curSum < 0)
        {
            curSum = 0;
        } 
    } 

    return maxSum;
}


long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{   
    long long maxSubSum;

    if (k == 1)
    {
        maxSubSum = kadane(arr, n, k);

        return maxSubSum;
    }

    int arrSum = 0;

    for (int i = 0; i < n; i++)
    {
        arrSum += arr[i];
    }

    if (arrSum <= 0)
    {   
        // Finding the maximum subarray sum for k = 2.
        maxSubSum = kadane(arr, n, 2);   
    }
    else
    {
        // Finding the maximum subarray sum for k = 2.
        maxSubSum = kadane(arr, n, 2);
        maxSubSum += (long long)(k - 2) * (long long)arrSum;
    } 

    return maxSubSum;
}
