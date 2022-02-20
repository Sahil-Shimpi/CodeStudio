// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118519/offering/1376725

#include <iostream>

using namespace std;

int countBits(int n) {
    int count = 0;
    while (n) {
        if(n%2 == 0)
        {
            n /= 2;
        }
        else
        {
            count++;
            n -= 1;
            n /= 2;
        }
    }
    return count;
}

int main() {
    int n;
    cin >> n;
    cout<<countBits(n);
    return 0;
}
