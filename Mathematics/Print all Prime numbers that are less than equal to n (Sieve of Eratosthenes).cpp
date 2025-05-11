#include <bits/stdc++.h>
using namespace std;

/***********************************************/
// Sieve of Eratosthenes
// Print all Prime numbers that are <= n
/*
    Input1: 10
    Output1: 2 3 5 7
    
    Input2: 23
    Output2: 2 3 5 7 11 13 17 19 23
    
    Input3: 50
    Output3: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
    
    Input4: 83
    Output4: 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83
    
    Input5: 2
    Output5: 2
    
    Input6: 7
    Output6: 2 3 5 7
    
    Input7: 19
    Output7: 2 3 5 7 11 13 17 19
*/

void sieve(int n)
{
    vector<bool> isPrime(n + 1, true);

    for (int i = 2; i <= n; i++)
    {
        if (isPrime[i])
        {
            cout << i << " ";

            for (int j = i * i; j <= n; j = j + i)
                isPrime[j] = false;
        }
    }
}

// TC: O(n log (log n))
/***********************************************/

int main() {

    int n;

    cin >> n;

    sieve(n);

    return 0;
}
