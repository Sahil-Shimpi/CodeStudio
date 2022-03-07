// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381865?leftPanelTab=0

/*
   Time Complexity: O(Q)
   Space Complexity: O(Q),

   Where 'Q' is the number of queries
*/

vector<int> xorQuery(vector<vector<int>> &queries)
{
	// Create an empty array ans
	vector<int>ans;

	// Create an array xorArray of the size of 10^5+1 initialized with 0
	vector<int> xorArray(100001, 0);
    
    // Iterate over all the queries
	for (int i = 0; i < queries.size(); i++)
	{
		if (queries[i][0] == 1)
		{
			ans.push_back(queries[i][1]);
		}
		else
		{
			xorArray[0] ^= queries[i][1];
			xorArray[ans.size()] ^= queries[i][1];
		}

	}

	// Computing cumulative prefix XOR and evaluating the answer
	for (int i = 0; i < ans.size(); i++)
	{
		if (i == 0)
		{
			ans[i] = ans[i] ^ xorArray[i];
		}
		else
		{
			xorArray[i] ^= xorArray[i - 1];
			ans[i] ^= xorArray[i];
		}

	}

	return ans;
}
