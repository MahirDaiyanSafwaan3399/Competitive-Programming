#include <iostream>
#include <bits/stdc++.h>

using namespace std;

long long f_nine_one(long long n)
{
    if (n >= 101)
    {
        return (n - 10);
    }
    else
    {
        return f_nine_one(f_nine_one(n + 11));
    }
}

int main()
{
    while (true)
    {
        long long x = 0;
        cin >> x;

        if (x == 0)
        {
            break;
        }
        else
        {
            cout << "f91(" << x << ") = " << f_nine_one(x) << endl;
        }
    }
}