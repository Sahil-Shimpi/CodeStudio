// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377952

/*
        Time complexity : O(logN)
        Space complexity : O(1),

        where N is the number of empty pens.
*/

int recyclePens(int n, int r, int k, int c ) 
{

    // Our answer will be between 0 and n.
    // left will represent the lower limit of search space and right will represent the upper limit.
    int left = 0 , right = n , ans = 0;
    // We will do binary search between left to right.
    while (left <= right) 
    {
        // We will try to find out whether we can make x usable pens or not.
        // recycleReward is the money you will get when you sell n-x empty pens.
        // totalMoney is the amount of money in the pocket after selling n-x empty pens.
        // Using totalMoney we will try to buy x pens.
        // penCost is the money required to buy x refills.
        long long x = (left + right) / 2;
        long long recycleReward = (long long)(n - x) * k;
        long long totalMoney = r + recycleReward;
        long long penCost = (long long)c * x;
        // If we can buy x pens then we will update answer and compress the search space to right half.
        // Else we will compress the search space to left half.
        if (totalMoney >= penCost) 
        {
            ans = x;
            left = x + 1;
        }

        else 
        {
            right = x - 1;
        }

    }

    // return the final answer.
    return ans;
}
