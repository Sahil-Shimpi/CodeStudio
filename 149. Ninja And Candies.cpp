// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377958

/*
	Time complexity: O(sumCandy * log(sumCandy))
	Space complexity: O(sumCandy * log(sumCandy))
	
	where sumCandy is the total number of candy which Ninja has to buy. 
*/

bool isPossible(int currDay, vector<int>& days, vector<int>& candies, int n, int m, vector<int>& k)
{
	// Computing the last day of sale for each candies
	vector<int> last(n + 1, -1);
	for(int i = 0; i < m; ++i) 
	{
		if (days[i] <= currDay) 
		{
			last[candies[i]] = max(last[candies[i]], days[i]);
		}
	}

	vector<vector<int>> lastDay(currDay +1);

	/*
		For each day we are storing in a list all the candies
		which have the i-th day as the last day of sale
	*/  
	for(int i = 0; i < n; ++i) 
	{
		if (last[i+1] != -1) 
		{
			lastDay[last[i+1]].push_back(i);
		}
	}

	vector<int> need = k;

	int currMoney = 0;

	for(int i = 1; i <= currDay; ++i) 
	{
		currMoney++;

		for(int j = 0; j < lastDay[i].size(); j++) 
		{
			if (currMoney >= need[lastDay[i][j]]) 
			{
				currMoney -= need[lastDay[i][j]];
				need[lastDay[i][j]] = 0;
			} 
			else 
			{
				need[lastDay[i][j]] -= currMoney;
				currMoney = 0;
				break;
			}
		}
	}

	int sum = 0;

	for(int i = 0; i < n; i++)
	{
		sum += need[i];
	}

	return ((sum * 2) <= currMoney);
}

int minimumDays(vector<int>& days, vector<int>& candies, vector<int>& k, int n, int m)
{
	int high=0;

	for(int i = 0; i < n; i++)
	{
		high += k[i];
	}

	high*=2;

	if(high == 0)
	{
		return 0;
	}

	int low=1;

	while(low <= high)
	{
		int mid = (low + high) / 2;

		if(isPossible(mid, days, candies, n, m, k))
		{
			high = mid - 1;
		} 
		else
		{
			low = mid + 1;
		}
	}

	return high + 1;

}
