// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377945

/*
    Time Complexity: O(log(N)+log(M))
    Space Complexity: O(1)

    Where 'N' is the number of rows and 'M' is the number of columns in the given matrix.

*/

bool findInMatrix(int x, vector<vector<int>> &arr)
{
    int n = arr.size();
    int m = arr[0].size();

    //    Binary search the complete matrix.
    int low = 0, high = (n - 1) * m + m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;

        //    Find the current element of the matrix.
        int row = mid / m, col = mid % m;
        
        //    Element found.
        if (arr[row][col] == x)
        {
            return true;
        }
        
        //    Reduce the search space
        else if (arr[row][col] > x)
        {
            high = mid - 1;
        }

        //    Reduce the search space.
        else
        {
            low = mid + 1;
        }
    }

    //    Element is not present in the matrix.
    return false;
}
