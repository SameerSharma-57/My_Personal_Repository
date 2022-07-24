#include <iostream>
using namespace std;

void join_array(const double arr1[], const int n1, const double arr2[], const int n2)
{
   double arr[n1+n2];
    for (int i = 0; i < n1; i++)
    {
        *(arr + i) = *(arr1 + i);
    }
    for (int i = 0; i < n2; i++)
    {
        *(arr + n1 + i) = *(arr2 + i);
    }
    for (int i = 0; i < n1 + n2; i++)
    {
        cout << *(arr + i) << " ";
    }
    cout << endl;
}
int main()
{
    # ifndef ONLINE_MODE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    # endif
    int n1;
    
    
    cout << "enter the length of first array" << endl;
    cin >> n1;
    double arr1[n1];
    cout << "enter the first array" << endl;
    for (int i = 0; i < n1; i++)
    {
        cin >> *(arr1 + i);
    }
    int n2;
    
    cout << "enter the length of second array" << endl;
    cin >> n2;
    double arr2[n2];
    cout << "enter the second array" << endl;
    for (int i = 0; i < n2; i++)
    {
        cin >> *(arr2 + i);
    }
    // int n1,n2;
    // n1=2;n2=2;
    // double arr1[n1]={1,2};
    // double arr2[n2]={3,4};
    
    
    join_array(arr1, n1, arr2, n2);

    return 0;
}