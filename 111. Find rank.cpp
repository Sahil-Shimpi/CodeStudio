// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118821/offering/1381915

/*
   Time Complexity: O((N^2)*M)
   Space Complexity: O(N*M)

   Where 'N' is the number of rows and 'M' is the number of columns
*/

// Function to find the transpose of the matrix
void transpose(vector<vector<int>> &arr, int n, int m)
{
	vector<vector<int>> temp(m, vector<int>(n));

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			temp[j][i] = arr[i][j];
		}
	}

	arr = temp;
}

// Function for swapping the rows
void swapRow(vector<vector<int>> &arr, int n1, int n2, int m)
{
	int i, j, temp;
	for (i = 0; i < m; i++)
	{
		temp = arr[n1][i];
		arr[n1][i] = arr[n2][i];
		arr[n2][i] = temp;
	}
}

// Function for swapping the columns
void swapCol(vector<vector<int>> &arr, int m1, int m2, int n)
{
	int i, j, temp;
	for (i = 0; i < n; i++)
	{
		temp = arr[i][m1];
		arr[i][m1] = arr[i][m2];
		arr[i][m2] = temp;
	}
}

int findRankOfMatrix(vector<vector<int>> &arr)
{
	int n = arr.size();
	int m = arr[0].size();

	// If number of N is greater then M then do transpose of the matrix
	if (n > m)
	{
		transpose(arr, n, m);
		int temp = n;
		n = m;
		m = temp;
	}

	// Now create a variable swapCol equal to M - 1 which will be used when we have to swap the columns
	int swapPos = m - 1;
	int i, j, k;

	// Iterate through each row
	for (i = 0; i < n; i++)
	{
		// If there is a non-zero diagonal element then we have to make all the elements in the current column to zero except the diagonal element
		if (arr[i][i])
		{
			for (j = 0; j < n; j++)
			{
				if (j != i)
				{
					if (arr[j][i])
					{
						double multiplier = (double)arr[j][i] / arr[i][i];
						for (k = 0; k < m; k++)
						{
							arr[j][k] -= multiplier * arr[i][k];
						}
					}
				}
			}
		}

		// If the diagonal element is zero
		else
		{
			// Find if there exists a row with a non - zero enetry in same column
			// If so swap these tow rows and break the loop
			bool isSwapped = false;
			for (j = i + 1; j < n; j++)
			{
				if (arr[j][i])
				{
					swapRow(arr, i, j, m);
					isSwapped = true;
					break;
				}
			}

			// Now check if isSwapped is equal to false then swap the current column i with the column represented by swapCol and decrement the value of swapCol by one
			if (!isSwapped)
			{
				if (swapPos > i)
				{
					swapCol(arr, i, swapPos, n);
					swapPos--;
				}
				else
				{
					break;
				}
			}

			// Now decrease the value of i by one so that the row can be processed again
			i--;
		}
	}

	// Rank will be equal to non-zero diagonal element in each row
	int rank = 0;
	for(i = 0; i < n; i++)
	{
		if(arr[i][i])
        {
            rank++;
        }
		else
        {
            break;
        }
	}

	return rank;
}
