//Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118784/offering/1381040

#include <iostream>
using namespace std;

int main() {
    
    char ip;
    int ascii;
    cin >> ip;
    ascii = (int)ip;
    
    if(ascii >= 65 && ascii <= 90) 
    {
        cout << 1 << endl;
    }
    
    else if(ascii >= 97 && ascii <= 122)
    {
        cout << 0 << endl;
    }
    
    else 
    {
        cout << -1 << endl;
    }

    return 0;
}
