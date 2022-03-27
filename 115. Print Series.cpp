// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380916?leftPanelTab=0

/*
    Time Complexity  : O(N)
    Space Complexity : O(N)

    Where N is the given number.
*/

void series(int n, int k, vector<int> &answer)
{
    
    // Add n to answer
    answer.push_back(n);

    // If n<=0 then break the recursion
    if (n <= 0)
    {
        return;
    }

    // Recur for series(answer, n, n-k).
    series(n - k, k, answer);

    // Add n to answer.
    answer.push_back(n);
}

vector<int> printSeries(int n, int k)
{
    
    // Declare an empty array to store our series
    vector<int> answer;

    // Call the series function
    series(n, k, answer);

    // Return the answer
    return answer;
}
