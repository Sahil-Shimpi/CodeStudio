// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376579

/*
    Time Complexity = O(N)
    Space Complexity = O(K)

    Where N is the length of the array and K is the given distance.
*/

#include <unordered_set>

bool checkDuplicate(vector<int> &arr, int n, int k) {

    // Creating set for storing elements within 'k' range
    unordered_set<int> window;

    for (int i = 0; i < n; i++) {

        /*
        	If the window already contain current element
			i.e we find duplicate element within the 'k' 
			distance from each other.
		*/
        if (window.find(arr[i]) == window.end()) {

            // Adding current element to window.
            window.insert(arr[i]);
        }

        else {
            return true;
        }

        // For sliding window ,remove the (i-k)th from window.
        if (i >= k) {
            window.erase(arr[i - k]);
        }

    }

    // There is no duplicate element within the 'k' distance from each other.
    return false;
}
