#include <iostream>
#include <bits/stdc++.h>

#define endl "\n"
#define MOD 1e9 + 7

typedef long long ll;

using namespace std;

void solve(ll x, ll y)
{
    vector<ll> nums;

    ll temp = y;

    int count = 1;
    nums.push_back(temp);
    while (y != x and y > 0)
    {
        if ((y % 10) == 1)
        {
            y = (y - 1) / 10;
            
        }
        else if (y % 2 == 0)
        {
            y = y / 2;
        }
        else
        {
            break;
        }
        nums.push_back(y);
        count++;
    }

    if (x == y)
    {
        cout << "YES" << endl
             << count << endl;
        for (int i = count - 1; i >= 0; i--)
        {
            cout << nums[i] << " ";
        }

        cout << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
}

int main()
{
    ll x, y;
    cin >> x >> y;
    solve(x, y);
}
