#include <iostream>
using namespace std;
void sort_arr(double arr[], int n)
{
    void sort_numbers(double *, double *);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            sort_numbers(arr + i, arr + j);
        }
    }
}
void sort_numbers(double *num1, double *num2)
{
    if (*num1 < *num2)
    {
        int temp = *num1;
        *num1 = *num2;
        *num2 = temp;
    }
}

void reverse(double arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        double temp = *(arr + i);
        *(arr + i) = *(arr + n - i - 1);
        *(arr + n - i - 1) = temp;
    }
}

int main()
{
    /*
    (a) sort the numbers in increasing order
    (b) sort the numbers in decreasing order
    (c) find maximum number
    (d) find minimum number
    (e) Do nothing
    */
    int n;
    cout << "enter the length of array" << endl;
    cin >> n;
    double arr[n];
    cout << "enter the array" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << " select one operation\n"
         << "1. sort the numbers in increasing order\n"
         << "2. sort the numbers in decreasing order\n"
         << "3. find maximum number\n"
         << "4. find minimum number\n"
         << "5. Do nothing" << endl;
    int q;
    cin >> q;
    switch (q)
    {
    case 1:
        sort_arr(arr, n);
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    case 2:
        sort_arr(arr, n);
        for (int i = n - 1; i >= 0; i--)
        {
            cout << arr[i] << " ";
        }
        break;
    case 3:
        sort_arr(arr, n);
        cout << arr[n - 1];

        break;
    case 4:
        sort_arr(arr, n);
        cout << arr[0];
        break;
    case 5:
        break;
    default:
        break;
    }

    return 0;
}