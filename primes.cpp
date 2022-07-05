#include <bits/stdc++.h>

using namespace std;

const int size = 1e5;

#define N 10000

int mark[N];

void sieve()
{
    // Mark all as primes
    for (int i = 0; i < N; i++)
    {
        mark[i] = 1;
    }

    mark[1] = 0;
    int LIM = sqrt(N);
    for (int i = 2; i <= LIM; i++)
    {

        for (int j = i * i; j < N; j += 2 * i)
        {
            mark[j] = 0;
        }
    }
}

bool is_prime(int x)
{
    if (x <= 1)
    {
        return false;
    }

    int LIM = sqrt(x);

    for (int i = 2; i <= LIM; i++)
    {
        if (x % i == 0)
        {
            return false;
        }
    }
    return true;
}

void primeFactors(int n)
{
    // Print the number of 2s that divide n
    while (n % 2 == 0)
    {
        cout << 2 << " ";
        n = n / 2;
    }

    // n must be odd at this point. So we can skip
    for (int i = 3; i <= sqrt(n); i = i + 2)
    {
        // While i divides n, print i and divide n
        while (n % i == 0)
        {
            cout << i << " ";
            n = n / i;
        }
    }

    // This condition is to handle the case when n is a prime number greater than 2
    if (n > 2)
        cout << n << " ";
}

bool almost_prime(int n)
{
    // almost prime number has only 4 factors;
    // 1,p1,p2,p1*p2;
    // where p1 and p2 are prime and p1 != p2; We need to find p1 and p2;
    // p1 || p2 != 1 so only 2 remaining choice so we return false after the smallest divisor after 1;

    // a*b  = n then a <= sqrt(n);

    int LIM = sqrt(n);
    for (int i = 2; i <= LIM; i++)
    {
        if (n % i == 0)
        {
            // i is a factor
            // n/i is a factor
            // i != n/i
            if (is_prime(i) && is_prime(n / i) && i != n / i)
            {
                cout << i << " " << n / i << ": " << n << endl;
                return true;
            }
            else
            {
                return false;
            }
        }
    }
    return false;
}
int cnt[1000];

void count_factors(int n)
{

    for (int i = 1; i <= n; i++)
    {
        // for (int j = i; j <= n; j+= i){
        //     cnt[i]++;
        // }
        cnt[i] = n / i;
    }
}

int main()
{
    sieve();

    for (int i = 1; i < N; i++)
    {
        // cout << mark[i] << " ";
        if (mark[i] == 1)
        {
            cout << i << endl;
        }
    }

    // primeFactors(1457);
    // for (int i = 1; i <= 300; i++)
    // {
    //     if (almost_prime(i)){
    //         // cout << almost_prime(i) << endl;
    //     }
    // }
    // count_factors(36);
    // cout << cnt[12] << endl;
}