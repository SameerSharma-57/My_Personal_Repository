#include <iostream>

using namespace std;

int main()
{
    int n1;
    int arr1[n1];
    cout << "Enter length of first array"<<endl;
    cin >> n1;
    cout << "Enter the first array"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> arr1[i];
    }
    int n2;
    int arr2[n2];
    cout << "Enter length of second array"<<endl;
    cin >> n2;
    cout << "Enter the second array"<<endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> arr2[i];
    }
    int n3 = n1+n2;
    int arrf[n3];
    for (int i = 0; i < n1 + n2; i++)
    {
        while(i<n1){
            arrf[i] = arr1[i];
        }
        while(i>=n1){
            arrf[i] = arr2[i+n1];
        }
    }
    for(int i =0;i<n3;i++){
        cout<<arrf[i]<<" ";
    }

    return 0;
}