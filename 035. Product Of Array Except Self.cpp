// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381866

/*
    Time Complexity : O(N)
    Space complexity : O(1)

    where N is the size of the input array
*/

int multiply(int a, int b)
{
    int mod = 1e9 + 7;
    long long ret = a % mod;
    ret *= (b % mod);
    ret = ret % mod;
    return ret;
}

int *getProductArrayExceptSelf(int *arr, int n)
{
    int *output = new int[n];
    int product = 1;

    for (int i = 0; i < n; ++i) 
    {
        output[i] = product;
        product = multiply(product, arr[i]);
    }

    product = 1;

    for (int i = n - 1; i >= 0; --i) 
    {
        output[i] = multiply(product, output[i]);
        product = multiply(product, arr[i]);
    }

    return output;
}
