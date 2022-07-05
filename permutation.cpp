#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string permutation = "";
int used[30];


// Takes in a pos which is by default 1 and string s and prints all the permutation of the string
void print_permutation(int pos, string s)
{
    // Base case;
    if(pos > s.length()){
        cout << permutation << endl;
        return;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (used[s[i] - 'A'] == 0)
        {
            permutation[pos-1] = s[i];
            used[s[i] - 'A'] = 1;
            print_permutation(pos + 1,s);
            used[s[i] - 'A'] = 0;
        }
    }
}

int main()
{
    string s;
    cin >> s;

    for (int i = 0; i < 26;i++){
        used[i] = 0;
    }
    for (int i = 0; i < s.length();i++)
        permutation += 'A';

    // Prints all the permutation of s;
    print_permutation(1, s);
}