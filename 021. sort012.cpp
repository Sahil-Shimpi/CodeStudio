// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118787/offering/1381280

#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    int c0 = 0;
    int c1 = 0;
    int c2 = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            c0++;
        }
        else if(arr[i] == 1)
        {
            c1++;
        }
        else
        {
            c2++;
        }
    }
    for(int i=0; i<c0; i++)
    {
        arr[i] = 0;
    }
    for(int i=c0; i<c0+c1; i++)
    {
        arr[i] = 1;
    }
    for(int i=c0+c1; i<c0+c1+c2; i++)
    {
        arr[i] = 2;
    }
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort012(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        t--;
    }
    return 0;
}

// Alternate Approach: Dutch National Flag Algorithm

void sort012(int *arr, int n)
{
    int low = 0;
    int mid = 0;
    int high = n-1;
    
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low += 1;
            mid += 1;
        }
        else if(arr[mid] == 1)
        {
            mid += 1;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high -= 1;
        }
    }
}


