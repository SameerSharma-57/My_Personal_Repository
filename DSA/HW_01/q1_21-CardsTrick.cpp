#include <iostream>
using namespace std;

int findInd(int arr[], int elem, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == elem)
        {
            return i;
        }
    }
}

void pile(int arr[], int ind)
{

    int r = ind / 7;
    if (r == 1)
    {
        for (int i = 0; i < 21; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    for (int i = 0; i < 7; i++)
    {
        int temp = arr[7 + i];
        arr[7 + i] = arr[7 * r + i];
        arr[7 * r + i] = temp;
    }
    for (int i = 0; i < 21; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void distribute(int arr[])
{
    int out[21];
    for (int i = 0; i < 21; i++)
    {
        int r = i % 3;
        int q = i / 3;
        out[7 * r + q] = arr[i];
    }
    for (int i = 0; i < 21; i++)
    {
        arr[i] = out[i];
    }
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int arr[21];
    for (int i = 0; i < 21; i++)
    {
        cin >> arr[i];
    }

    int c;
    cin >> c;
    distribute(arr);
    pile(arr, findInd(arr, c, 21));
    distribute(arr);
    pile(arr, findInd(arr, c, 21));
    distribute(arr);
    pile(arr, findInd(arr, c, 21));
    

    return 0;
}
