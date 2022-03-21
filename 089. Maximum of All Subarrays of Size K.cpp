// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376580

/*
	Time Complexity  : O(N)
	Space Complexity : O(K)

	Where N is the length of the given array and K is the given subarray size.
*/

#include <deque>

vector<int> maximumInAllSubarraysOfSizeK(vector<int> arr, int n, int k)
{

	// Declare an empty array to store maximum of all k sized subarrays
	vector<int> answer;

	//Declare an empty deque to maintain a window of indices
	deque<int> indexWindow;

	// Run a loop and iterate through all elements of the array
	for (int i = 0; i < n; i++)
	{

		// If the front element of the deque is out of bound from the current window then remove it
		if (indexWindow.empty() == false and indexWindow.front() == i - k)
		{
			indexWindow.pop_front();
		}

		// Remove the rightmost indices of deque until the element at this index is smaller than
		// The current element i.e. arr[i]
		while (indexWindow.empty() == false and arr[i] > arr[indexWindow.back()])
		{
			indexWindow.pop_back();
		}

		// Push index of current element to window
		indexWindow.push_back(i);

		// If size of window is greater than k then add
		// Element having index equals to front element of deque
		// To answer
		if (i >= k - 1)
		{
			answer.push_back(arr[indexWindow.front()]);
		}
	}

	// Return the answer
	return answer;
}
