#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void merge_sort(int arr[], int L, int R)
{

    if (L == R)
    {
        return;
    }

    int mid = (L + R) / 2;
    merge_sort(arr, L, mid);
    merge_sort(arr, mid + 1, R);

    int i = L, j = mid + 1;

    vector<int> nums;
    while (i <= mid and j <= R)
    {
        if (arr[i] < arr[j])
        {
            nums.push_back(arr[i]);
            i++;
        }
        else
        {
            nums.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {
        nums.push_back(arr[i]);
        i++;
    }
    while (j <= R)
    {
        nums.push_back(arr[j]);
        j++;
    }
    for (int i = 0; i < nums.size(); i++)
        arr[i + L] = nums[i];
}

int main()
{

    int arr[] = {32, 12, 0, -1, 98, 34, 12, 35, 12, 6, 23, 56, 23};
    merge_sort(arr, 6, 12);

    for (int i = 0; i < 13; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}