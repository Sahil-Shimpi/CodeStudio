// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382138?leftPanelTab=0

/*
    Time complexity: O(N)
    Space complexity: O(1)

    where 'N' is number elements in 'ARR'.
*/

vector<int> waveFormArray(vector<int> &arr, int n) 
{
    // Iterate only even indices.
    for (int i = 0; i < n; i += 2) 
    {
        // Check is previous element is greater or not.
        if (i > 0 && arr[i] < arr[i - 1]) 
        {
            // Swap 'arr[i]' and 'arr[i-1]'.
            swap(arr[i], arr[i - 1]);
        }

        // Check is next element is greater or not.
        if (i < n - 1 && arr[i] < arr[i + 1]) 
        {
            // Swap 'arr[i]' and 'arr[i-1]'.
            swap(arr[i], arr[i + 1]);
        }
    }
    return arr;
}
