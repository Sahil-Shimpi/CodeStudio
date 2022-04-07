// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377961?leftPanelTab=1

/*

	Time Complexity: O(N * log(N))
	Space Complexity: O(N)
	
	Where N is the number of intervals.

*/

#include<algorithm>

vector<int> smartInterval(vector<vector<int>> &intervals, int n)
{
	// Create two array of pairs
	vector<pair<int, int>>sortedStarts(n), sortedEnds(n);

	for(int i = 0; i < n; i++)
	{
		sortedStarts[i] = {intervals[i][0], i};
		sortedEnds[i] = {intervals[i][1], i};
	}

	// Sort the arrays
	sort(sortedStarts.begin(), sortedStarts.end());
	sort(sortedEnds.begin(), sortedEnds.end());

	// Output array
    vector<int>result(n, -1);

    int i = 0, j = 0;

    // Traverse through the arrays 
    while(i < n and j < n)
    {
    	// Smart interval is found
    	if(sortedStarts[i].first >= sortedEnds[j].first)
    	{
    		int index = sortedEnds[j].second;
    		result[index] = sortedStarts[i].second;
    		j++;
    	}
    	else
    	{
    		i++;
    	}
    }

    return result;  
}
