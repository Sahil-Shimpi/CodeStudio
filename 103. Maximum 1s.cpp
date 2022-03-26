// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381908

/*
   Time Complexity: O(N+M)
   Space Complexity: O(1)

   Where ‘N’ is the number of rows, and the ‘M’ is the number of columns
*/

int maxOne(vector<vector<int>> &arr)
{
	int n = arr.size();
	int m = arr[0].size();

	// Create a variable currentColum initialized to M-1
	// Create a variable row initialized to -1
	int currentColumn = m - 1;
	int row = -1;

	// Iterate through each row and column exactly once
	for (int i = 0 ; i < n ; i++)
	{
		while (currentColumn >= 0 && arr[i][currentColumn] == 1)
		{
			currentColumn = currentColumn - 1;
			row = i;
		}
	}

	// Return the answer
	return row;
}

