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

void replace(int* arr,int t,int r){
    for (int i = 0; i < 9; i++)
    {
        int temp = arr[9 * t + i];
        arr[9 * t + i] = arr[9 * r + i];
        arr[9 * r + i] = temp;
    }

}
void pile(int arr[], int ind, int t)
{

    int r = ind / 9;
    if (r == t)
    {
        for (int i = 0; i < 27; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    
    
        replace(arr,t,r);
    

    if ((t == 0 && r == 2) || (t == 2 && r == 0))
    {
        replace(arr,r,1);
    }
    for (int i = 0; i < 27; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void distribute(int arr[])
{
    int out[27];
    for (int i = 0; i < 27; i++)
    {
        int r = i % 3;
        int q = i / 3;
        out[9 * r + q] = arr[i];
    }
    for (int i = 0; i < 27; i++)
    {
        arr[i] = out[i];
    }

    cout << endl;
}
int main()
{
// #ifndef ONLINE_MODE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif

    int arr[27];
    for (int i = 0; i < 27; i++)
    {
        cin >> arr[i];
    }
    int a, n;
    cin >> a >> n;
    n = n - 1;
    for (int i = 0; i < 3; i++)
    {
        int r = n % 3;

        n = n / 3;
        distribute(arr);
        pile(arr, findInd(arr, a, 27), r);
    }

    return 0;
}