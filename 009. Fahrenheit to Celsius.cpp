// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118784/offering/1381074

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int s, e, w;
    float c; //celcius value
    int temp; //temporary value to be used in loop
    cin >> s >> e >> w;
    
    for(int i=s; i<=e; i=i+w)
    {
        c = (i - 32) * 5 / 9;
        if(c < 0) 
        {
            temp = ceil(c);
        }
        else
        {
            temp = floor(c);
        }
        cout << i << "\t" << temp << "\n";
    }

    return 0;
}
