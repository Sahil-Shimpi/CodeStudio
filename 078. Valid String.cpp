// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376560

/*
    Time Complexity: O(N)
    Space Complexity:  O(1)

    Where 'N' is the length of the string.
*/

bool checkValidString(string s) {
    int lower = 0, upper = 0;
    for (char c : s){

        if (c=='(') {
            lower++;
            upper++;
        } 

        else if (c==')') {
            lower--;               
            upper--;
        }

        // '*' encountered.
        else{ 
            lower--;
            upper++;
        }

        lower = max(lower, 0);

        // Unmatched ')' found in the middle of string.
        if (upper<0) 
        {
            return false;
        }
    }
    return lower == 0;
}
