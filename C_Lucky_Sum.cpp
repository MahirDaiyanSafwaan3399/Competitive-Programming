#include <bits/stdc++.h>

using namespace std;

set<string> lucky_numbers;

void generate_lucky(int len)
{

    for (int mask = 0; mask < (1 << len); mask++)
    {
        string number = "";
        for (int i = 0; i < len; i++)
        {
            if ((mask & (1 << i)) > 0)
            {
                number += "4";
            }
            else
            {
                number += "7";
            }
        }

        lucky_numbers.insert(number);
    }
}

int main()
{
    string l, r;
    cin >> l >> r;
    for (int i = 1; i <= 10; i++)
    {
        generate_lucky(i);
    }

    for (string x : lucky_numbers)
    {
        cout << x << endl;
    }

    // int x = l.length();
    // int y = r.length();
}