// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381904

/*
    Time Complexity: O(N^2)
    Space Complexity: O(1)

    where ‘N’ is the side length of the given square matrix.
*/

void inplaceRotate(vector<vector<int>> &inputArray)
{
	int n = inputArray.size();
	for (int x = 0; x < n / 2; x++)
	{
		for (int y = x; y < n - x - 1; y++)
		{
			int temp = inputArray[x][y];
			inputArray[x][y] = inputArray[y][n - 1 - x];
			inputArray[y][n - 1 - x] = inputArray[n - 1 - x][n - 1 - y];
			inputArray[n - 1 - x][n - 1 - y] = inputArray[n - 1 - y][x];
			inputArray[n - 1 - y][x] = temp;
		}
	}
}
