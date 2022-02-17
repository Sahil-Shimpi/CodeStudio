// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118784/offering/1381072

#include <iostream>
using namespace std;

int main() {
    
    int n, sum = 0;
    cin >> n;
    for(int i=0; i<=n; i=i+2)
    {
        sum += i;
    }
    cout << sum << endl;

    return 0;
}
