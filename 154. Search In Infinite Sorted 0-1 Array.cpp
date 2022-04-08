// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118621/offering/1377963?leftPanelTab=0

/*
    Time Complexity - O(logX)
    Space Complexity - O(1)

    Where X is the index of first 1 in the infinite array.
*/


// Function to find first 1 in a segment using Binary Search.
long long findOne(long long start, long long end)
{
    // Declare a variable to store the index .
    long long finalIndex;

    while(start <= end)
    {
        // Find mid index of the segment.
        long long mid = start + (end - start) / 2;

        /*
            If the value at mid index is 0, update
            the start to mid + 1
            Else, update the finalIndex to mid, and
            end to mid - 1.
        */
        if(get(mid) == 0)
        {
            start = mid + 1;
        }
        else
        {
            finalIndex = mid;
            end = mid - 1;
        }
    }

    // Return the final index.
    return finalIndex;
}

long long firstOne()
{
    // Variables to keep track of current segment.
    long long start = 0, end = 0;

    // Update our segment until there are all 0s in it.
    while(get(end) == 0)
    {
        start = end + 1;
        end = 2LL * start - 1;

        // If end is less than start, update it to start.
        if(end < start)
        {
            end = start;
        }
    }

    // Find the first 1 in the segment.
    long long index = findOne(start, end);

    // Return index.
    return index;
}
