// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1382160

/*  
    Time Complexity : O(N)
    Space Complexity : O(1)
    
    Where 'N' is the length of Encrypted String 'S'.
*/

char kThCharaterOfDecryptedString(string s, long long k)
{
    long long i, j;

    //  Length of the Encrypted String.
    long long n = s.length();

    //  To store the length of the substring.
    long long substringLength;

    //  To store the resultant length of the repeated substring.
    long long resultantLength;

    // To store the frequency of the substring.
    long long freqOfSubstring;

    //  'k'th Character in Decrypted String.
    char kThChar;

    i = 0;

    while (i < n)
    {
        j = i;
        substringLength = 0;
        freqOfSubstring = 0;

        // Find the length of substring by traversing the string until no digit is found.
        while (j < n && islower(s[j]))
        {
            j++;
            substringLength++;
        }

        // Find the frequency of preceding substring.
        while (j < n && isdigit(s[j]))
        {
            freqOfSubstring = freqOfSubstring * 10 + (s[j] - '0');
            j++;
        }

        // Find length of the resultant length of the repeated substring.
        resultantLength = freqOfSubstring * substringLength;

        if (k > resultantLength)
        {
            /*
                If length of the repeated substring is less than
                'k' then required character is present in later
                substring. Subtract the length of repeated
                substring from 'k' to keep account of number of
                characters required to be visited.
            */

            k -= resultantLength;
            i = j;
        }
        else
        {
            /*
                If length of repeated substring is
                more or equal to 'k' then required
                character lies in current substring.
            */

            k--;
            k %= substringLength;
            kThChar = s[i + k];
            break;
        }
    }

    return kThChar;
}
