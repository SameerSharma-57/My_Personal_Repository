#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int arr[3];
    for (int i = 0; i < 3; i++)
    {
        arr[i] = 0;
    }

    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        arr[val % 3] += 1;
    }
    int out1 = arr[1] < arr[2] ? arr[1] : arr[2];
    int out2 = arr[1] < arr[2] ? arr[2] - arr[1] : arr[1] - arr[2];
    cout << (arr[0] + out1 + (out2 / 3));

    return 0;
}