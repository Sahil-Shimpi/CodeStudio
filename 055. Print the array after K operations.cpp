// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381890

/*
	Time Complexity: O(N)
	Space Complexity: O(1)

	where N is size of the array.
*/

#include<algorithm>

vector<int> printArrayAfterKOperations(vector<int> &Arr, int N, int K) {

	if (K == 0) {
		return Arr;
	}

	vector<int> soln;

	// Finding maximum element value in Arr[].
	int maxm = *max_element(Arr.begin(), Arr.end());
	// Finding minimum element value in Arr[].
	int minm = *min_element(Arr.begin(), Arr.end());

	// If K is odd, then all array will be transformed to maxm - Arr[i].
	if (K & 1) {
		for (int i = 0; i < N; i++) {
			soln.push_back(maxm - Arr[i]);
		}

		return soln;
	}

	// Else if K is even, then all array will be transformed to minm - Arr[i].
	else {
		for (int i = 0; i < N; i++) {
			soln.push_back(Arr[i] - minm);
		}

		return soln;
	}

}
