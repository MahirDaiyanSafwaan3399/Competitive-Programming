#include <iostream>
#include <bits/stdc++.h>

using namespace std;

// Given Pattern
string given_pattern[5];

// saved grids of k
string answer[300];

// Used to generate the k th grid
string helper[300];

int generate_grid(int n, int k)
{
    // Generates a grid for every k steps and stores it in the answer an returns the size of the generated grid

    // Base case;
    if(k == 1){
        for (int i = 0; i < n; i++)
        {
            answer[i] = given_pattern[i];
        }
        return n;
    }

    // Get the size of the grid k-1;
    int size = generate_grid(n, k - 1);
    int new_size = size * n;
    
    // Initialize helper with black cells to generate the k th grid
    for (int i = 0; i < new_size; i++)
    {
        helper[i] = "";
        for (int j = 0; j < new_size; j++)
        {
            helper[i] += '*';
        }
    }

    // Running for the k-1 th grid stored in answer;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if(answer[i][j] == '*'){
                continue;
            }
            else{
                // Get the new row and col for the new grid;
                int row = i * n;
                int col = j * n;

                // Simply paint the corresponding cells with the given pattern
                for (int r = 0; r < n; r++)
                {
                    for (int c = 0; c < n; c++)
                    {
                        helper[row + r][col + c] = given_pattern[r][c];
                    }
                }
                
            }
        }
    }

    for (int i = 0; i < new_size; i++)
    {
        answer[i] = helper[i];
    }
    return new_size;
}

int main()
{
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> given_pattern[i];
    }

    int size = generate_grid(n, k);
    for (int i = 0; i < size; i++)
    {
        cout << answer[i] << endl;
    }
}