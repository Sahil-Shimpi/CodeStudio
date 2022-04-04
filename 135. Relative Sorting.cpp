// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382141

/*
    Time Complexity: O(N * log(N) + M * log(N))
    Space Complexity: O(N)

    Where N is size of ARR and M is size of BRR.
*/

#include <map>

vector<int> relativeSorting(vector<int> &arr, vector<int> &brr, int n, int m)
{
    // Maintain a HashMap 
    map<int, int> frequencyMap;
	
    // Traverse through the array ARR
    for (int i = 0; i < n; i++)
    {
        frequencyMap[arr[i]]++;
    }
	
    // Create an array result        
    vector<int> result;
	
    // Traverse through the array BRR
    for (int i = 0; i < m; i++)
    {
        int ele = brr[i];

        if (frequencyMap.find(ele) != frequencyMap.end())
        {
            int count = frequencyMap[ele];

            for (int j = 1; j <= count; j++)
            {
                result.push_back(ele);
            }

            frequencyMap.erase(ele);
        }
    }

    // Traverse through the HashMap        
    for (auto element : frequencyMap)
    {
        int ele = element.first;
        int count = element.second;

        for (int j = 1; j <= count; j++)
        {
            result.push_back(ele);
        }
    }
	
    // Return the array result
    return result;
}

