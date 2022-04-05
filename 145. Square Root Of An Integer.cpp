// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377953

/*

	Time complexity: O(log(A))
	Space complexity: O(1)
	
	where A is given in each test case.

*/

int squareRoot(int a)
{
	int start = 0, end = a;
    
    // Iterate until start < end
	while(start <= end)
	{
		int mid = (start + end)/2;
        
        // Search in right half.
		if(mid * mid <= a)
		{
			start = mid + 1;
		}
		
		// Search in left half
		else
		{
			end = mid - 1;
		}
	}

	return start - 1;
}
