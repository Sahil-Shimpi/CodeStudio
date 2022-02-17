// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118784/offering/1381076

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    int n;
    cin >> n;
    int temp;
    int odd = 0;
    int even = 0;
    while(n>0)
    {
        temp = n%10;
        n = floor(n/10);
        if (temp%2 == 0)
        {
            even += temp;
        }
        else
        {
            odd += temp;
        }
    }
    cout << even << " " << odd << "\n";

    return 0;
}
