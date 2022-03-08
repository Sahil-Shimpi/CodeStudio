// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870

long long maxSubarraySum(int arr[], int n)
{
    long long curr_sum = 0; // Current Sum of empty array
    long long glob_sum = 0; // Global Sum of empty array
    
    for(int i=0; i<n; i++)
    {
        curr_sum = (arr[i] > (curr_sum + arr[i]) ? arr[i] : (curr_sum + arr[i]));
        if(curr_sum > glob_sum)
        {
            glob_sum = curr_sum;
        }
    }
    
    return glob_sum;
}
