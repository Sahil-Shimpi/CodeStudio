// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381888

/*  
    Time Complexity : O(N)
    Space Complexity : O(1)

    Where 'N' is the size of Array.
*/

bool isPossible(int *arr, int n)
{

    int i, notInOrderIndex = -1;

    for (i = 0; i < n - 1; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            
            /*
				If more than 1 Index is not in non-decreasing
				order then we can return false.
			*/
            if (notInOrderIndex != -1)
            {
                return false;
            }

            notInOrderIndex = i;
        }
    }

    /*
		If Everyone is in Order OR Only First Number
		is not in Order OR Only Last
		number is not in Order.
	*/
    if (notInOrderIndex == -1 || notInOrderIndex == 0 || notInOrderIndex == n - 2)
    {
        return true;
    }

    /*
	    If we can change arr[notInOrderIndex]
		to be between arr[notInOrderIndex - 1]
	    and arr[notInOrderIndex + 1].
	*/
    if (arr[notInOrderIndex - 1] <= arr[notInOrderIndex + 1])
    {
        return true;
    }

    /*
		If we can change arr[notInOrderIndex + 1]
		to be between arr[notInOrderIndex]
		and arr[notInOrderIndex + 2].
	*/
    if (arr[notInOrderIndex] <= arr[notInOrderIndex + 2])
    {
        return true;
    }

    /*
	    If there is no way to make the array
		non-decreasing by modifying at most 1
	    element.
	*/
    return false;
}
