// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381883

#include <algorithm>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    sort(arr.begin(), arr.end());
    int ptr1 = 0;
    int ptr2 = arr.size() - 1;
    vector<vector<int>> ans;
    
    while(ptr1 < ptr2)
    {
        vector <int> temp;
        if(arr[ptr1] + arr[ptr2] > s)
        {
            ptr2--;
        }
        else if(arr[ptr1] + arr[ptr2] == s)
        {
            temp.push_back(arr[ptr1]);
            temp.push_back(arr[ptr2]);
            ptr2--;
        }
        else
        {
            ptr1++;
        }
        ans.push_back(temp);
    }
}
