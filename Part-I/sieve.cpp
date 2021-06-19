#include <bits/stdc++.h>
using namespace std;
 
int SieveOfEratosthenes(int n)
{
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= n; p++)
    {

        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
    
    int count = 0;

    for (int p = 2; p <= n; p++)
        if (prime[p])
            count++;

    return(count);
}
 
int main()
{
    int n = 1000000;
    cout << "Following are the prime numbers smaller "
         << " than or equal to " << n << endl;
    int countPrime = SieveOfEratosthenes(n);
    cout<< "Number of primes: " << countPrime <<"\n"; 
    return 0;
}