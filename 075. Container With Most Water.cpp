// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376555?leftPanelTab=0

/*
    Time Complexity: O(n)
    Space Complexity: O(1)

    Where 'n' is the number of elements in the sequence.
*/
int maxArea(vector<int>& height) {
    // Variable to store overall maximum area. Initially -1.
    int globalArea = -1;

    int startIndex = 0, endIndex = height.size() - 1;
    while (startIndex < endIndex) {
        // Minimum height calcuted to find the area.
        int minHeight = min(height[startIndex], height[endIndex]);

        globalArea = max(globalArea, (endIndex - startIndex) * minHeight);

        // If the start index has a smaller value than min height try to find a bigger value.
        if (height[startIndex] <= minHeight) {
            startIndex++;
        } else {
            // Otherwise, try to find a bigger value for end index.
            endIndex--;
        }
    }
    return globalArea;
}
