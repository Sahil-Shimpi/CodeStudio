// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377976

/*  
    Time Complexity : O(N)
    Space Complexity : O(N)

    Where 'N' is the length of the message string.
*/

string encode(string &message)
{
    int n = message.size(), i;

    string encodedMessage = "";

    for (i = 0; i < n; i++)
    {
        char curChar = message[i];
        int charFreq = 1;
        while (i + 1 < n && message[i + 1] == curChar)
        {
            i++;
            charFreq++;
        }

        encodedMessage.push_back(curChar);
        encodedMessage.append(to_string(charFreq));
    }

    return encodedMessage;
}
