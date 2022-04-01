// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118822/offering/1382140?leftPanelTab=0

/*
	Time Complexity:  O(N)
	Space Complexity: O(N),

	where N is the number of elements in the array.
*/

// Function to count the number of set bits in an integer
int countSetBits(int number)
{
	int count = 0;
	while (number != 0)
	{
		count += (number & 1);
		// Using bitwise right shift to divide the number by two
		number = number >> 1;
	}

	return count;
}

void sortSetBitsCount(vector<int>& arr, int size)
{
	vector<int>bitsCount[33];
	int val;
	for (int i = 0; i < size; i++)
	{
		val = countSetBits(arr[i]);
		bitsCount[val].push_back(arr[i]);
	}

	// Clearing the input array to store the result in this array.
	arr.clear();
	// Outer loop runs for 33 times( from 0-32 ) because we are taking into consideration 32 bit numbers only.
	for (int i = 32; i >= 0; i--)
	{
		for (int j = 0; j < bitsCount[i].size(); j++)
		{
			arr.push_back(bitsCount[i][j]);
		}
	}

}
