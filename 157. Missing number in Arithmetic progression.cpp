// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377969?leftPanelTab=2

int missingNumber(vector<int> &arr, int n) 
{
	int a = arr[0];
	int d;
	
	if(arr[1] - arr[0] == arr[2] - arr[1])
	{
		d = arr[1] - arr[0];
	}
	else if(arr[2] - arr[1] == 2 * (arr[1] - arr[0]))
	{
		d = arr[1] - arr[0];
	}
	else if(arr[1] - arr[0] == 2 * (arr[2] - arr[1]))
	{
		d = arr[2] - arr[1];
	}
	
	int low = 0;
	int high = n-1;
	int mid;
	
	while(low < high)
	{
		mid = low + (high - low)/2;
		
		if(arr[mid] - arr[mid - 1] == 2 * d)
		{
			return arr[mid] - d;
		}
		else if(arr[mid] == a + (mid * d))
		{
			low = mid + 1;
		}
		else
		{
			high = mid - 1;
		}
	}
}
