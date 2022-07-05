#include <bits/stdc++.h>

using namespace std;

bool contains_equal_digit(long long int n){
    string s = "";
    int len = 0;
    int four = 0, seven = 0;

    while(n){
        char digit = (n % 10) + '0';
        s += digit;
        if(digit == '4'){
            four++;
        }else if(digit == '7'){
            seven++;
        }
        len++;
        n = n / 10;
    }
    len /= 2;
    if ((four == len and seven == len))
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    long long int n;
    cin >> n;

    while(true){
        if(contains_equal_digit(n)){
            cout << n << endl;
            break;
        }
        else
        {
            n = n + 1;
        }
    }
    
}