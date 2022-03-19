// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376575?leftPanelTab=2

/*

    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where N is the length of the given array.

*/



#include<limits.h>

int threePointer(vector<int>& X, vector<int>& Y, vector<int>& Z)
{   
    // It keeps the track of minimum difference in the values. 
    int difference = INT_MAX;
    int minimum = INT_MAX;
    int maximum = INT_MIN;

    int i, j, k;
    for (i = 0, j = 0, k = 0; i < X.size() && j < Y.size() && k < Z.size();) {

        minimum = min(X[i], min(Y[j], Z[k]));
        maximum = max(X[i], max(Y[j], Z[k]));
        difference = min(difference, maximum - minimum);

        // If difference = 0, then we can return the difference as the minimum value.
        if (difference == 0) {
            break;
        }

        // If the element from the array X is minimum.
        if (X[i] == minimum) {
            i++;
        }

        // If the element from the array Y is minimum.
        else if (Y[j] == minimum) {
            j++;
        }

        // If the element from the array Z is minimum.
        else {
            k++;
        }
    }

    return difference;
}
