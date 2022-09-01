#include <iostream>
using namespace std;

void printArr(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 9 == 0 && i != 0)
        {
            cout << "\t";
        }
        cout << arr[i] << " ";
    }
    cout << endl;
    return;
}

void pile(int arr[], int r, int t)
{
    
    
    if (r == t)
    {
        printArr(arr,27);
        return;
    }
    for (int i = 0; i < 9; i++)
    {
        int temp = arr[9 * t + i];
        arr[9 * t + i] = arr[9 * r + i];
        arr[9 * r + i] = temp;
    }
   printArr(arr,27);
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
    printArr(arr,27);
}

int main()
{
    

    int arr[27];
    for (int i = 1; i < 28; i++)
    {
        arr[i - 1] = i;
    }

    int t, c;
    int base_3[3];
    printArr(arr,27);
    
    cout<<endl<<"Enter the card number (1 to 27): ";
    cin>>c;
    cout<<endl<<"Enter the position at which you want the card to appear (1 to 27): ";
    cin >> t;

    int temp = t-1;
    for (int i = 0; i < 3; i++)
    {
        base_3[2 - i] = temp % 3;
        temp = temp / 3;
    }
    int q1,q2,q3;
    printArr(arr,27);
    cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
    cin>>q1;
    
    pile(arr, q1-1, base_3[2]);
    distribute(arr);
    cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
    cin>>q2;
    pile(arr, q2-1, base_3[1]);
    distribute(arr);
    cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
    cin>>q3;
    pile(arr, q3-1, base_3[0]);
    cout << "Your chosen card is : "<<arr[t-1] << endl;

    return 0;
}
