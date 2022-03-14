// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118626/offering/1377975

string convertString(string str) 
{
	int n = str.size();
    if(str[0] > 96)
    {
        str[0] = str[0] - 32;
    }
    
    for(int i=1; i<n-1; i++)
    {
        if(str[i] == ' ')
        {
            if(str[i+1] > 96)
            {
                str[i+1] = str[i+1] - 32;
            }
        }
    }
    return str;
}
