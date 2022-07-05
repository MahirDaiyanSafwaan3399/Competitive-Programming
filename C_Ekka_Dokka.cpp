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
        int caseno = 1;
        while (T--)
        {
            long long w;
            cin >> w;

            if (w % 2 == 1)
            {
                cout << "Case " << caseno << ": Impossible" << endl;
                caseno++;
            }
            else
            {

                long int sqt = sqrt(w);
                for (int i = 2; i <= sqt; i++)
                {
                    if (w % i == 0)
                    {
                        if (i % 2 == 0 and (w / i) % 2 == 1)
                        {
                            cout << "Case " << caseno << ": " << w / i << " " << i << endl;
                            caseno++;
                            break;
                        }
                        else if (i % 2 == 1 and (w / i) % 2 == 0)
                        {
                            cout << "Case " << caseno << ": " << i << " " << w/i << endl;
                            caseno++;
                            break;
                        }
                    }
                }
            }
        }
    }
