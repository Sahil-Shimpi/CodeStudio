// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380925

/*
    Time Complexity: O(K ^ (N - K) * K!)
    Space Complexity: O(N)

    where N is the length of array ARR, and k is as given.
*/

bool splitIntoKUtil(vector<int> &arr, vector<int> &sumOfSubsets, vector<bool> &isElementConsidered, int subset, int K, int N, int currentIndex, int maxLimit) {
    
	// We found a distribution
    if (sumOfSubsets[currentIndex] == subset) 
    {
        if (currentIndex == K - 2) 
        {
            return 1;
        }

        // recursive call for next generation
        return splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, currentIndex + 1, N - 1);
    }

    for (int i = maxLimit; i >= 0; i--) 
    {
    	
    	// is taken already
        if (isElementConsidered[i]) 
        {
            continue;
        }
        int temp = sumOfSubsets[currentIndex] + arr[i];

        // check if ith element can be included in current subset
        if (temp <= subset) 
        {
            isElementConsidered[i] = 1;
            sumOfSubsets[currentIndex] += arr[i];
            
            // recursive call to check if a distribution is possible
            bool next = splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, currentIndex, i - 1);
            isElementConsidered[i] = 0;
            sumOfSubsets[currentIndex] -= arr[i];
            
            // found a distribution
            if (next) 
            {
                return true;
            }
        }
    }
    
    // did not find a distribution
    return 0;
}

// main function
bool splitArray(vector<int> &arr, int K) 
{
    int N = arr.size();
    if (K == 1) 
    {
        return true;
    }

    if (N < K) 
    {
        return false;
    }

    // Calculate sum of array
    int sum = 0;
    for (int i = 0; i < N; i++) 
    {
        sum += arr[i];
    }
    if (sum % K != 0) 
    {
        return false;
    }
    int subset = sum / K;

    vector<int> sumOfSubsets(K);
    vector<bool> isElementConsidered(N);

    for (int i = 0; i < K; i++) 
    {
        sumOfSubsets[i] = 0;
    }
    for (int i = 0; i < N; i++) 
    {
        isElementConsidered[i] = false;
    }

    sumOfSubsets[0] = arr[N - 1];
    isElementConsidered[N - 1] = true;

    // Check if a distribution exists
    return splitIntoKUtil(arr, sumOfSubsets, isElementConsidered, subset, K, N, 0, N - 1);
}
