#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve(vector<int> trees, long long basket_capacity)
{

    long long ans = 0;
    int n = trees.size();
    for (int mask = 0; mask < (1 << n); mask++)
    {
        long long max = 0;
        for (int i = 0; i < n; i++)
        {
            if ((mask & (1 << i)) > 0)
            {
                // Take all the apples from that tree
                max += trees[i];
            }
        }

        if (max <= basket_capacity)
        {
            ans = max;
        }
    }
    cout << ans << endl;
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int tree_no;
        long long basket_capacity;
        cin >> tree_no >> basket_capacity;
        vector<int> trees(tree_no);
        for (int i = 0; i < tree_no; i++)
        {
            cin >> trees[i];
        }
        solve(trees, basket_capacity);
    }
}