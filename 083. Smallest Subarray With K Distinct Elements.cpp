// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376574

/*
    Time Complexity: O(N)
    Space Complexity: O(N)

    where 'N' is the size of input array
*/

#include <unordered_map>

vector<int> smallestSubarrayWithKDistinct(vector<int> &arr, int k)
{
	
	int n = arr.size();
	
    /*
    start := start index of resultant subarray
    end  := end index of resultant subarray
    */
    int start = 0, end = n;

    unordered_map<int, int> map;

    /*
    i := start index of current subarray
    j := next index to the end of current subarray
    */
    int i = 0, j = 0;
    while (j < n)
    {
        //Add the current element to the map
        map[arr[j]]++;
        j++;
        
        /*
        If set contains exactly k elements, 
        consider subarray[i, j - 1], if it is smaller in size than the current resultant subarray 
        and keep removing left most elements
        */
        
        while (map.size() == k)
        {
            if (j - 1 - i < end - start)
            {
                start = i;
                end = j - 1;
            }

            //Remove elements from left
            if (map[arr[i]] == 1)
            {
                map.erase(arr[i]);
            }
            else
            {
                map[arr[i]]--;
            }

            i++;
        }
    }
    
    // Initialize array to store result
    vector<int> ans;

    // There is no subarray with K distinct elements
    if (end == n)
    {
        ans.push_back(-1);
    }
    else
    {
        //Subarray found
        ans.push_back(start);
        ans.push_back(end);
    }
    
    return ans;
}
