// Problem: https://www.codingninjas.com/codestudio/guided-paths/basics-of-c/content/118519/offering/1376726

#include <iostream>

using namespace std;

int totalPrime(int S, int E) {
    int flags[E-S+1] = {0}; // Initializing an array of flags keeping a track of all numbers in the given range checking whether they're prime or not.
    int count = 0; 
    for(int i=S; i<= E; i++)
    {
        for(int j=2; j<i; j++)
        {
            if(i%j == 0)
            {
                flags[i-S] = 1; // If we find that 2nd number from the given range is prime, we'll mark the second index (1 here) instead of the number itself as the index. 
                break;
            }
        }
    }
    for(int k=0; k<(E-S+1) ; k++)
    {
        if(flags[k] == 0)
        {
            count ++; // Counting number of primes
        }
    }
    return count;
}

int main() {
    int S, E;
    cin >> S >> E;
    cout << totalPrime(S, E);
    return 0;
}
