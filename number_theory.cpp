#include <bits/stdc++.h>

using namespace std;

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin >> n;
        vector<int> prize(n);
        for (int i = 0; i < n; i++)
        {
            cin >> prize[i];
        }

        sort(prize.begin(), prize.end());

        long long sum = 0;
        for (int i = n-1; i >= 0; i--)
        {
            sum += prize[i];
        }

        cout << sum-prize[0] << endl;
    }
}