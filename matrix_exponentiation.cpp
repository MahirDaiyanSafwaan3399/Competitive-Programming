#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct matrix
{
    int mat[2][2];
};

typedef struct matrix Matrix;

Matrix identity()
{
    // 2D matrix
    Matrix identity;
    identity.mat[0][0] = 1;
    identity.mat[0][1] = 0;
    identity.mat[1][0] = 0;
    identity.mat[1][1] = 1;

    return identity;
}

Matrix multiply(Matrix m1, Matrix m2)
{
    // 2 by 2 matrix
    Matrix multiplied;

    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                sum += m1.mat[i][k] * m2.mat[k][j];
            }
            multiplied.mat[i][j] = sum;
            sum = 0;
        }
    }
    return multiplied;
}

Matrix exponentiation(Matrix M, int N)
{
    // Base case;
    if (N == 0)
    {
        // M ^ 0 = identity matrix
        // (m^2) * (m^0) = (m^2)
        return identity();
    }

    Matrix x = exponentiation(M, N / 2);

    if (N % 2 == 0)
    {
        return multiply(x, x);
    }
    else
    {
        return multiply(multiply(x, x), M);
    }
}

int get_nth_fibonacci(int N)
{
    Matrix fib;
    fib.mat[0][0] = 1;
    fib.mat[0][1] = 1;
    fib.mat[1][0] = 1;
    fib.mat[1][1] = 0;

    Matrix ans = exponentiation(fib, N);

    // [fn + N]
    // [fn + N-1]
    return ans.mat[1][0] + ans.mat[1][1];
}

int main()
{
    while (true)
    {
        int n;
        cin >> n;
        if (n == -1)
        {
            break;
        }
        cout << "The " << n << "th one is: " << get_nth_fibonacci(n - 1) << endl;
    }
}