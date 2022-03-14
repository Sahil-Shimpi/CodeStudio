// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377990

/*
	Time Complexity: O(N)
	Space Complexity: O(1)

	Where N is the length of the string.
*/
string nextLargestPalindrome(string s, int length)
{
	// Initializing carry to keep track of the carry forward at the time of addition.
	int carry = 1, temp;
	// Loop to add 1 to the number represented by string S.
	for (int i = length - 1; i >= 0; i--)
	{
		if ((s[i] - 48) + carry <= 9)
		{
			s[i] = char((s[i] - 48) + carry + 48);
			carry = 0;
		}

		else
		{
			temp = (s[i] - 48 + carry) % 10;
			s[i] = char(temp + 48);
			carry = 1;
		}

	}

	if (carry != 0){
		s = char(carry + 48) + s;
	}

	int i = 0, j = s.length() - 1, pos;
	bool conditionViolated = false;
	// Converting string s to a palindrome.
	while (i <= j)
	{
		if (s[i] < s[j])
		{
			s[j] = s[i];
			pos = i;
			conditionViolated = true;
		}

		else if (s[i] > s[j])
		{
			s[j] = s[i];
			conditionViolated = false;
		}

		else if (conditionViolated && s[i] != '9')
		{
			pos = i;
		}

		i++;
		j--;
	}

	// Checking if the condition is violated or not.
	// Finding the smallest palindrome strictly greater than the input number.
	if (conditionViolated)
	{
		s[pos]++;
		s[s.length() - 1 - pos] = s[pos];
		for (int i = pos + 1; i <= (s.length() - 1) / 2; i++)
		{
			s[s.length() - 1 - i] = s[i] = '0';
		}

	}

	return s;
}
