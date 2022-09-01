#include <iostream>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int sum = 0;
    int n, k;
    cin >> n >> k;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        if (i < k)
        {
            sum += arr[i];
        }
    }
    int out = sum;
    for (int i = 0; i < k; i++)
    {
        sum = sum + arr[n - i - 1] - arr[k - 1 - i];
        if (out < sum)
        {
            out = sum;
        }
    }
    cout << out << endl;

    return 0;
}