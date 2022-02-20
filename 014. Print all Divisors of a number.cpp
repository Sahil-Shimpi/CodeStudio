// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118519/offering/1376722

#include <iostream>

using namespace std;

void printDivisors(int n) {
    for(int i=1; i<n; i++)
    {
        if(n%i == 0)
        {
            cout << i << " ";
        }
    }
    cout << n;
}

int main() {
    int n;
    cin >> n;
    printDivisors(n);
    return 0;
}
