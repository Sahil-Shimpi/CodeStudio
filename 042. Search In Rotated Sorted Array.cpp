// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381878?leftPanelTab=2

int binarySearch(int* arr, int low, int high, int key)
{
    int mid;
    while(low <= high)
    {
        mid = low + (low + high)/2;
        if(arr[mid] == key)
        {
            return mid;
        }
        else if(arr[mid] < key)
        {
            high = mid - 1;
        }
        else 
        {
            low = mid + 1;
        }
    }
    return -1;
}

int search(int* arr, int n, int key) 
{
    int mx = arr[0];
    int idx; // Index at which the highest element is present
    for(int i=1; i<n; i++)
    {
        if(arr[i]<mx)
        {
            idx = i - 1;
            break;
        }
        else
        {
            mx = arr[i];
        }
    }
    int ans = binarySearch(arr, 0, idx, key);
    if(ans == -1)
    {
        ans = binarySearch(arr, idx+1, n-1, key);
    }
    return ans;
    
}
