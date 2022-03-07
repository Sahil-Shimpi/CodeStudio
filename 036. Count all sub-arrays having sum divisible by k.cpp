// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381867

/*
    
    Time complexity: O(N + K)
    Space complexity: O(K)

    where 'N' is number elements in 'ARR' and 'K' is given second integer.
*/

int subArrayCount(vector<int> &arr, int k) {
    // To store frequency of every remainder.
    vector<int> remArr(k, 0);

    // To store prefix sum.
    long pre = 0;

    for (int i = 0; i < arr.size(); i++) {
        pre += arr[i];
        // If current remainder is 'x' then increase remainder 'x' frequency by '1'.
        remArr[((pre % k) + k) % k] = remArr[((pre % k) + k) % k] + 1;
    }

    int count = 0;  // To store count of the all subarray has sum is divisible by 'k'.

    // Iterate every occurence of remainder.
    for (int i = 0; i < k; i++) {
        if (remArr[i] > 1) {
            // Total subarray with particular remainder.
            int totalPossibleCombination = ((remArr[i] * (remArr[i] - 1)) / 2);
            count = count + totalPossibleCombination;
        }
    }

    // Add remainder '0' frequency.
    count += remArr[0];

    return count;
}
