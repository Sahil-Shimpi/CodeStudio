// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118509/offering/1376571

bool isSubSequence(string str1, string str2) 
{
    int n1 = str1.length();
    int n2 = str2.length();
    int i = 0;
    int j = 0;
    while(i < n1 && j < n2)
    {
        if(str1[i] == str2[j])
        {
            i++;
            j++;
        }
        else
        {
            j++;
        }
    }
    if(i == n1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
