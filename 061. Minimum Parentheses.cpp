// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377977

/*
    Time complexity: O(n)
    Space complexity: O(1)

    Where 'n' is number of character in 'pattern' string.
*/

int minimumParentheses(string pattern) 
{
    int openBr = 0;   // To store count of '('
    int closeBr = 0;  // To store count of ')'
    int count = 0;    // Count of minimum parentheses required

    for (int i = 0; i < pattern.length(); i++) 
    {
        if (pattern[i] == '(') 
        {
            openBr += 1;
        } 
        else 
        {
            closeBr += 1;
        }

        // If ')' is greater than '('
        if (closeBr > openBr) 
        {
            count += (closeBr - openBr);
            openBr = 0;
            closeBr = 0;
        }
    }

    count += (openBr - closeBr);

    return count;
}
