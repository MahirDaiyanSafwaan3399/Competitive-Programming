#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int cnt[30], k;

string ans;

void perm(int pos, int n)
{

    if (pos == n)
    {
        cout << ans << endl;
        k--;
        return;
    }
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] > 0)
        {
            cnt[i]--;
            ans[pos] = i + 'A';
            perm(pos + 1, n);
            cnt[i]++;
            if (k == 0)
                return;
        }
    }
}

int main()
{

    int t, caseno = 1;
    cin >> t;
    while (t--)
    {
        string str;
        int n;
        cin >> n >> k;
        ans = "";
        for (int i = 0; i < n; i++)
            ans += "A";

        memset(cnt, 0, sizeof cnt);

        for (int i = 0; i < n; i++)
        {
            cnt[i]++;
        }
        cout << "Case " << caseno++ << ":\n";
        perm(0, n);
    }
    return 0;
}
