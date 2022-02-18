// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118784/offering/1381078

#include <iostream>
using namespace std;

int main() {
    
    int x,n;
    cin >> x >> n;
    int temp = 1;
    
    if(n == 0)
    {
        cout << 1 << endl;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            temp *= x;
        }
        cout << temp << endl;
    }

    return 0;
}
