// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118787/offering/1381279?leftPanelTab=0

/* Iterative Approach
1) We first sort the Array so that we can access the K smallest elements at the beginning and K largest elements at the end.
2) We keep a counter to store the number of distinct elements encountered till now.
3) As soon count reaches K we print the current element and break.
4) Similarly, we do it for the Kth largest element as well.
5) If our counter remains < K after the whole loop we report that answer doesn't exist and print -1. */


#include <bits/stdc++.h>
using namespace std;

void kthSmallestLargest(int arr[], int n, int k) {
    sort(arr, arr + n);
    //kthlargest
    int z = n - 1;
    int mn = INT_MAX;
    int count = 0;
    int flag = 0;

    while (z >= 0) {

        if (arr[z] < mn) {
            mn = arr[z];
            count++;
        }
        if (count == k) {
            flag = 1;
            cout << arr[z] << " ";
            break;
        }

        z--;
    }
    if (flag == 0)
        cout << -1 << " ";

    // kthSmallest
    count = 0;
    mn = INT_MIN;
    flag = 0;

    for (int i = 0; i < n; i++) {

        if (arr[i] > mn) {
            mn = arr[i];
            count++;
        }
        if (count == k) {
            flag = 1;
            cout << arr[i] << endl;
            break;
        }
    }
    if (flag == 0)
        cout << -1 << endl;
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        kthSmallestLargest(arr, n, k);
        cout << endl;
        t--;
    }
    return 0;
}
