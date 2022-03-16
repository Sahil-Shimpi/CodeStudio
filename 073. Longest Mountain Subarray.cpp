// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376554

/*
    Time Complexity: O(N)
    Space Complexity: O(1)

    where 'N' is the size of the given array.
*/

int longestMountain(int *arr, int n)
{
    if(n < 3)
    {
    	return 0;
    }

    int start = -1, end = -1;
    int ans = 0;

    for (int i = 0; i < n - 1; ++i)
    {
    	if(arr[i+1] > arr[i])
    	{
    		if(end != -1) {
    			end = -1;
    			start = -1;
    		}

    		if(start == -1) {
	    		start = i;
	    	}
    	}
    	else
    	{
    		if(arr[i+1] < arr[i])
    		{
    			if(start != -1) {
    				end = i + 1;
    			}

    			if(end != -1 && start != -1) {
    				ans = max(ans, end - start + 1);
    			}
    		}
    		else
    		{
    			start = -1;
    			end = -1;
    		}
    	}
    }

    if(end != -1 && start != -1)
    {
    	ans = max(ans, end - start + 1);
    }

    return ans;
}
