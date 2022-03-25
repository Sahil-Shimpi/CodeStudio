// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381905?leftPanelTab=0

/*
	Time Complexity: O(K)
	Space Complexity: O(K)

	Where 'K' is the number of tasks.
*/

#include<set>

vector<long> emptyCells(int n, int k, vector<vector<int>> &tasks)
{
	int rows = n;
	int columns = n;

	vector<long> ans(k);

	set<int> rowSet;
	set<int> colSet;

	for (int i = 0; i < k; i++)
	{
		int x = tasks[i][0];
		int y = tasks[i][1];

		if (rowSet.find(x) == rowSet.end()) {
			rowSet.insert(x);
			rows--;
		}

		if (colSet.find(y) == colSet.end()) {
			colSet.insert(y);
			columns--;
		}
		ans[i] = (long)rows * (long)columns;
	}

	return ans;
}
