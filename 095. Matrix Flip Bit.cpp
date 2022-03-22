// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381898

/*
	Time Complexity : O(N ^ 2)
	Space Complexity : O(1)

	Where 'N' is the number of rows and columns in matrix 'MAT'.
*/

int countFlip(vector<vector<int>> &mat)
{
	int n = mat.size(), row = 0, col = 0, zeros = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				zeros++;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[i][j] == 0)
			{
				row++;
				break;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (mat[j][i] == 0)
			{
				col++;
				break;
			}
		}
	}

	int res = (n * row) + ((n - row) * col) - zeros;

	return res;
}
