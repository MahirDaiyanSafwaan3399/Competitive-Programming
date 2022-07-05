#include <iostream>
#include <bits/stdc++.h>

#define endl "\n"
#define MOD 1e9 + 7

typedef long long ll;

using namespace std;

int max(vector<int> arr)
{
    int max = arr[0];
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            index = i;
        }
    }

    return index;
}

int min(vector<int> arr)
{
    int min = arr[0];
    int index = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= min)
        {
            min = arr[i];
            index = i;
        }
    }

    return index;
}
int main()
{
    int n;
    cin >> n;
    vector<int> heights(n);

    for (int i = 0; i < n; i++)
    {
        cin >> heights[i];
    }
    int min_pos = min(heights) + 1, max_pos = max(heights);
    // cout << min_pos << endl;

    if (max_pos == 0 && min_pos == n)
    {
        cout << 0 << endl;
    }
    else if (max_pos + 1 < min_pos)
    {
        cout << max_pos + (n - min_pos) << endl;
    }
    else
    {
        min_pos++;
        cout << max_pos + (n - min_pos) << endl;
    }
}
