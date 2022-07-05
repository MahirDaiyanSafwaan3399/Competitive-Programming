#include <bits/stdc++.h>

using namespace std;

vector<long long int> lens;

int sequence(int n, long long int k)
{
    if (n == 1)
    {
        return 1;
    }

    // Lens always odd as 2^n - 1
    long int mid = (lens[n - 1] + 1) / 2;

    if (k == mid)
    {
        return n;
    }
    else if (k < mid)
    {
        return sequence(n - 1, k);
    }
    else
    {
        return sequence(n - 1, k - mid);
    }
}

int main()
{
    int n;
    long long int k;
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        lens.push_back((1LL << i) - 1);
    }
    // Prints N th sequence kth element
    cout << sequence(n, k) << endl;
}