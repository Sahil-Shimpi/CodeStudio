// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382160?leftPanelTab=0

/*
   Time Complexity : O(N*M)
   Space Complexity : O(N+M)
   
   where N and M are lengths of strings a and b respectively
   
*/

#include<vector>


string multiplyStrings(string a, string b) {

    int n = a.length();
    int m = b.length();

    // Initialising the answer vector with zeros 
    vector < int > answer(m + n, 0);

    // Below two indexes are used to find positions in answer.  
    int p = 0;
    int q = 0;

    // Traversing first number from right to left
    for (int i = n - 1; i >= 0; i--) {
        int carry = 0;

        // Initializing current digit of first number
        int a1 = a[i] - '0';

        // Initialising q to zero to denote right end
        q = 0;

        // Go from right to left in second number             
        for (int j = m - 1; j >= 0; j--) {
            // Taking current digit of second number 
            int a2 = b[j] - '0';

            // Multiply with digit of first number and adding carry to it
            int sum = a1 * a2 + answer[p + q] + carry;

            // Carry for next iteration 
            carry = sum / 10;

            // Storing the answer
            answer[p + q] = sum % 10;

            // Shifting q by 1
            q++;
        }

        // Store carry in the next cell if it exists
        if (carry > 0) {
            answer[p + q] += carry;
        }

        // Left shifting p by 1 unit 
        p++;
    }

    // Moving to first non-zero digit from left
    int i = answer.size() - 1;
    while (i >= 0 && answer[i] == 0) {
        i--;
    }

    // Generate the final answer as a string
    string result;

    while (i >= 0) {
        result += ('0' + answer[i--]);
    }
    
   // Checking the case of 0
   if( result.length()==0){return "0";}
    return result;
}

