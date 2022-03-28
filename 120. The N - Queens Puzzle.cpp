// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380923

/*

    Time Complexity : O(N!)
    Space Complexity : O(N * N)
    
    Where N is the number of Queens.

*/

//Function to add valid configuration
void addSolution(int n, vector<vector<int>>& ans, vector<int>& queensInRows) 
{
    vector<int> currentAnswer;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (queensInRows[j] == i) 
            {
                currentAnswer.push_back(1);
            } 
            else 
            {
                currentAnswer.push_back(0);
            }
        }
    }

    ans.push_back(currentAnswer);
}

void nQueensHelper(int col, int n, vector<vector<int>>& ans, vector<int>& queensInRows, vector<int>& queensInDiag1, vector<int>& queensInDiag2) 
{
    // If all the queens have been placed
    if (col == n) 
    {  
        addSolution(n, ans, queensInRows);
        return;
    }

    // Try all the rows for column col
    for (int i = 0; i < n; i++) 
    {                   
        // If its not safe to place queen here              
        if ((queensInRows[i] != -1) || (queensInDiag1[col - i + n - 1] != -1) || (queensInDiag2[col + i] != -1))
        {
            continue;
        }                    

        // Mark queen placed
        queensInRows[i] = queensInDiag1[col - i + n - 1] = queensInDiag2[col + i] = col;    

        // Try placing the remaining queens
        nQueensHelper(col + 1, n, ans, queensInRows, queensInDiag1, queensInDiag2);     

        // Unmark the cell to backtrack
        queensInRows[i] = queensInDiag1[col - i + n - 1] = queensInDiag2[col + i] = -1;  

    }

    return;
}


vector<vector<int>> nQueens(int n)
{
    vector<vector<int>> ans;
    vector<int> queensInRows(n, -1), queensInDiag1(2 * n, -1), queensInDiag2(2 * n, -1);

    nQueensHelper(0, n, ans, queensInRows, queensInDiag1, queensInDiag2);

    return ans;
}
