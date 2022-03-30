// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118522/offering/1380930

/*
	Time complexity: O(2 ^ N)
	Space complexity: O(N)

	where N is the given number

 */

void printParanthesesHelper(string str, int pos, int n, int open, int close) 
{
    
    // Close store the count of closing paranthesis
    if (close == n) 
    {
        
        // Print the possible combinations
        for (int i = 0; i < str.length(); i++) 
        {
            cout << str[i];
        }
        cout << endl;
        return;
    } 
    
    else
    {
        
        // Open store the count of opening paranthesis
        if (open > close) 
        {
            str[pos] = '}';
            printParanthesesHelper(str, pos + 1, n, open, close + 1);
        }
        if (open < n) 
        {
            str[pos] = '{';
            printParanthesesHelper(str, pos + 1, n, open + 1, close);
        }
    }
}

void printParantheses(int n) 
{
    
    // Initialising with any charecter
    string str(2 * n, 'a');  
    printParanthesesHelper(str, 0, n, 0, 0);
}
