// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118787/offering/1381276

#include <iostream>
using namespace std;

int main() {
    
    int n,x;
    int arr[n];
    bool flag = 0;
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    cin >> x;
    for(int i=0; i<n; i++)
    {
        if(x==arr[i])
        {
            cout << i << endl;
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        cout << -1 << endl;
    }
    

    return 0;
}
