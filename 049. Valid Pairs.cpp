// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381885

/*
    Time Complexity: O(N)
    Space Complexity: O(N)
    
    Where 'N' denotes the length of the array.
*/

#include <unordered_map>

bool isValidPair(vector<int> &arr, int n, int k, int m) 
{
    
	// An odd length array cannot be divided into pairs.
    if (n % 2 == 1) 
	{
        return false;
    }

    /*
	    Create a frequency array to count occurrences
        of all remainders when divided by k.
	*/
    unordered_map<int, int> map;

    for (int i = 0; i < n; i++) 
	{
        int rem = arr[i] % k;
        map[rem]++;
    }

    unordered_map<int, int>:: iterator itr;

    for(itr = map.begin(); itr != map.end(); itr++)  
	{
        int rem = itr->first;

        /*
	        If current remainder divides
            m into two halves.
		*/
        if (2 * rem == m) 
		{

            // Then there must be even occurrences of such remainder.
            if (map[rem] % 2 == 1)
			{
                return false;
            }
        }

        /* 
		    Else number of occurrences of remainder
            must be equal to number of occurrences of m - remainder.
	    */
        else 
		{
            if (map[(m - rem + k) % k] != map[rem]) 
			{
                return false;
            }
        }
    }

    return true;
}
