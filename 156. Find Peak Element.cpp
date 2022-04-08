// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377967

/*
    Time Complexity: O(log(n))
    Space Complexity: O(1)

    Where 'n' is the number of elements
*/

int findPeak(vector<int> &arr) 
{
    int n = arr.size();

    // Single element
    if (n == 1) 
	{
        return arr[0];
    }
    // Strictly descreasing
    if (arr[0] >= arr[1]) 
	{
        return arr[0];
    }
    // Strictly increasing
    if (arr[n - 1] >= arr[n - 2]) 
	{
        return arr[n - 1];
    }
    // Binary search
    int l = 1, r = n - 2;
    int ans = l;
    while (l <= r) 
	{
        int middle = (l + r) / 2;

        if (arr[middle] < arr[middle - 1]) 
		{
            // Search the left half
            r = middle - 1;
        } 
		else if (arr[middle] < arr[middle + 1]) 
		{
            // Search the right half
            l = middle + 1;
        } 
		else 
		{
            // Ans found
            ans = middle;
            break;
        }
    }
    return arr[ans];
}
