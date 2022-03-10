// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381880?leftPanelTab=2

/*
	Time Complexity: O(log(N))
	Space Complexity: O(1)

	Where N is the size of the sorted array.
*/

pair<int, int> findFirstLastPosition(vector<int> &arr, int n, int x)
{
	// Initialise both first and last occurrences to -1, incase X is not found in array.
	int idx1 = -1, idx2 = -1;
	// Binary search to find the first position of occurrence of X.
	int lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		// If arr[mid] == X and X > arr[mid-1], then mid is first occurrence of X, or arr[mid] == X and mid == 0, then mid is first occurrence of X.
		if ((mid == 0 or x > arr[mid - 1]) and arr[mid] == x) {
			idx1 = mid;
			break;
		}

		// If X is greater than arr[mid] in sorted array, then X may only occur in [mid+1, hi] range of index.
		else if (x > arr[mid]) {
			lo = mid + 1;
		}

		// Else X may only occur in [lo, mid-1] range of index.
		else {
			hi = mid - 1;
		}

	}

	// Binary search to find the last position of occurrence of X.
	lo = 0, hi = n - 1;
	while (lo <= hi) {
		int mid = (lo + hi) / 2;
		// If arr[mid] == X and mid == N-1 then, mid is last occurrence of X, or arr[mid+1] > X and arr[mid] == X, then mid is last occurrence of X.
		if ((mid == n - 1 or x < arr[mid + 1]) and arr[mid] == x) {
			idx2 = mid;
			break;
		}

		// If X < arr[mid], then X may only occur in [lo, mid-1] range of index.
		else if (x < arr[mid]) {
			hi = mid - 1;
		}

		// Else X may only occur in [mid+1, hi] range of index.
		else {
			lo = mid + 1;
		}

	}

	pair<int, int> sol;
	sol.first = idx1;
	sol.second = idx2;
	return sol;
}

