#include <iostream>
#include <bits/stdc++.h>

#define endl "\n"
#define MOD 1e9 + 7

typedef long long ll;

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> coins(n);
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> coins[i];
        sum += coins[i];
    }
    sort(coins.begin(), coins.end());
    int sum_back = 0;
    int cnt = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        sum_back += coins[i];
        // biggest_coin at i;
        if(sum_back <= (sum-sum_back)){
            cnt++;
        }
    }

    cout << cnt << endl;
}
