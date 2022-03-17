// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376565

string removeConsecutiveDuplicates(string str) 
{
    int n = str.length();
    string ans = "";
    int i = 0;
    int j = 0;
    if(n == 1)
    {
        return str;
    }
    while(j<n)
    {
        if(str[i] == str[j])
        {
            j++;
        }
        else
        {
            ans += str[i];
            i = j;
            j++;
        }
    }
    ans += str[n-1];
    return ans;
}
