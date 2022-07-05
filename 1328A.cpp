#include <iostream>
#include <bits/stdc++.h>

#define endl "\n"
#define MOD 1e9 + 7

typedef long long ll;

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int a, b;
        cin >> a >> b;

        if (a % b == 0)
        {
            cout << 0 << endl;
        }
        else
        {

            cout << b - (a % b) << endl;
        }
    }
}
