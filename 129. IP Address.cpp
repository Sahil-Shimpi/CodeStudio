// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380924

/*
	Time Complexity  : O(1)
	Space Complexity : O(1)

*/

#include <algorithm>

// Function to check whether a part of substring
// Can form a valid IP address or not
bool check(string &s)
{
	int n = s.size();
	// If number has leading zero then return false
	if (s[0] == '0' and (n != 1))
	{
		return false;
	}

	// If number of digits greater than 3 then return false
	if (n > 3)
	{
		return false;
	}

	// Calculate value of number in decimal form
	int number = 0, base = 1;
	for (int index = n - 1; index >= 0; index--)
	{
		int digit = s[index] - '0';
		number += (digit * base);
		base *= 10;
	}

	// If number lies between 0 and 255 then return true else return false.
	return (number >= 0 and number <= 255);
}
// n denotes length of original string
int n;

// Backtracking function
void backtracking(string &s, vector<string> &answer, vector<string> &segments, int curIndex, int segmentIndex)
{

	// Base case 1 , We have found a valid IP address, add it to the answer
	if (curIndex == n && segmentIndex == 4)
	{
		string temp = segments[0] + "." + segments[1] + "." + segments[2] + "." + segments[3];
		answer.push_back(temp);
		return;
	}

	// If we have reached till the last index or segment then break the recursion as
	// This path will be invalid.
	if (segmentIndex == 4 or curIndex == n)
	{
		return;
	}

	// Declare a string to store string for current segment
	string currentString = "";

	// We have 3 choices here either go 1 or 2 or 3 steps forward and
	// Take 1 or 2 or 3 digits to current segment
	for (int steps = 0; (steps <= 2) && (steps + curIndex < n); steps++)
	{
		currentString.push_back(s[curIndex + steps]);

		// If current string is invalid then it means this path is invalid so we skip the current itertion.
		if (check(currentString) == false)
		{
			continue;
		}

		// We have found a correct a path so move to next segment
		segments[segmentIndex] = currentString;
		backtracking(s, answer, segments, curIndex + steps + 1, segmentIndex + 1);
	}
}
vector<string> generateIPAddress(string s)
{
	vector<string> answer, segments(4);
	n = s.size();
	backtracking(s, answer, segments, 0, 0);
	// Sort the answer
	sort(answer.begin(), answer.end());

	// Return the answer
	return answer;
}
