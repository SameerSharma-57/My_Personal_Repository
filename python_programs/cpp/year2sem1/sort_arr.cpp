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

int main()
{
    int n;
    cout<<"enter the length of the arr to be sorted"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    
    sort_arr(arr,n);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}