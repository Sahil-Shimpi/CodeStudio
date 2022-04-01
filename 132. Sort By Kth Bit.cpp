// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382138?leftPanelTab=2

/*

    Time Complexity : O(N)
    Space Complexity : O(N)

    Where N is the number of elements in the array.

    
*/

vector < int > sortArrayByKBit(int n, int k, vector < int > & arr) 
{
    int j = 0;
    int p = 0;

    vector < int > temparr(n);

    // Loop to through arr.
    for (int i = 0; i < n; i++) 
    {
        // If Kth bit of current element is 0.
        if ((arr[i] >> (k - 1)) % 2 == 0) 
        {
            arr[p] = arr[i];
            p++;
        }
        // If Kth bit of current element is 1.
        else 
        {
            temparr[j] = arr[i];
            j++;
        }
    }

    j = 0;
    // Copy elements from temparr back to arr.
    for (int i = p; i < n; i++) 
    {
        arr[i] = temparr[j];
        j++;
    }
    // Return modified array.
    return arr;
}
