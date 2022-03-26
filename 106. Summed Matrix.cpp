// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381910

/*
    Time Complexity: O(1)
    Space Complexity: O(1)

*/

long long int query(long long int n, long long int q) 
{
    if (q == 0 || q > 2 * n) 
    {
        return 0;
    }
    if (q <= n + 1) 
    {
        return q - 1;
    } 
    else 
    {
        // Mathematical computation
        return n + n + 1 - q;
    }
}
