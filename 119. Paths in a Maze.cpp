// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380921

/*
    Time Complexity: O(3^( N^2))
    Space Complexity: O(3^( N^2))

    Where 'N' is the number of rows and columns in the given matrix.

*/

int di[] = {1, -1, 0, 0};
int dj[] = {0, 0, 1, -1};
char d[] = {'D', 'U', 'R', 'L'};


bool isValidMove(int i, int j, vector<vector<bool> > &visited, vector<vector<bool> > &arr)
{
    return (i >= 0 && j >= 0 && i < arr.size() && j < arr[i].size() && arr[i][j] == 1 && !visited[i][j]);
}

void allPossiblePaths(int i, int j, string &currentPath, vector<string> &allPaths, vector<vector<bool>> &visited, vector<vector<bool>> &arr)
{

    //    If the current cell is blocked return.
    if (arr[i][j] == false)
    {
        return;
    }

    int n = arr.size();
    //    If we have reached the destination cell then add the current path to the answer.
    if (i == n - 1 && j == n - 1)
    {
        allPaths.push_back(currentPath);

        return;
    }

    //    Mark the current cell as visited
    visited[i][j] = true;

   for (int x = 0 ; x < 4; x++) 
        {
            int newI = i + di[x];
            int newJ = j + dj[x];

            if (isValidMove(newI , newJ, visited, arr)) 
            {
                //    Push corresponding direction to the current path.
                currentPath.push_back(d[x]);

                //    Recursively traverse all paths from (i+1, j).
                allPossiblePaths(newI, newJ, currentPath, allPaths, visited, arr);

                //    Pop 'D' from the current path
                currentPath.pop_back();
            }
        }


    //    Mark the current cell as unvisited.
    visited[i][j] = false;
}

vector<string> findAllPaths(vector<vector<bool>> &arr)
{
    //    For storing all paths from (0,0) to (N-1, N-1)
    vector<string> allPaths;

    int n = arr.size();

    //    For marking all visited cells
    vector<vector<bool>> visited(n, vector<bool>(n, false));

    //    For storing the current path
    string currentPath = "";

    allPossiblePaths(0, 0, currentPath, allPaths, visited, arr);

    //    Return all the stored paths.
    return allPaths;
}
