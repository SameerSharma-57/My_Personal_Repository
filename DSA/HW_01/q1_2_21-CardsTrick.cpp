#include <iostream>
using namespace std;

// void printArr(int arr[], int size)
// {
//     for (int i = 0; i < size; i++)
//     {
//         if (i % 7 == 0 && i != 0)
//         {
//             cout << "\t";
//         }
//         cout << arr[i] << " ";
//     }
//     cout << endl;
//     return;
// }

// void pile(int arr[], int r)
// {

    
//     if (r == 1)
//     {
//         printArr(arr, 21);

//         return;
//     }
//     for (int i = 0; i < 7; i++)
//     {
//         int temp = arr[7 + i];
//         arr[7 + i] = arr[7 * r + i];
//         arr[7 * r + i] = temp;
//     }
//     printArr(arr, 21);
// }

// void distribute(int arr[])
// {
//     int out[21];
//     for (int i = 0; i < 21; i++)
//     {
//         int r = i % 3;
//         int q = i / 3;
//         out[7 * r + q] = arr[i];
//     }
//     for (int i = 0; i < 21; i++)
//     {
//         arr[i] = out[i];
//     }
//     printArr(arr, 21);
// }

// int main()
// {

//     int arr[21];
//     for (int i = 1; i < 22; i++)
//     {
//         arr[i - 1] = i;
//     }

//     int c, q1, q2, q3;
//     printArr(arr, 21);
//     cout<<endl<<"Enter the card number (1 to 21): ";
//     cin >> c;
//     cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
//     cin>>q1;
//     pile(arr, q1-1);
//     distribute(arr);
//     cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
//     cin >> q2;
//     pile(arr, q2-1);
//     distribute(arr);
//     cout<<endl<<"Enter the column in which the chosen card is located (1,2 or 3): ";
//     cin >> q3;
//     pile(arr, q3-1);
//     cout << "Your chosen card is : "<<arr[10] << endl;

//     return 0;
// }
void replace(int* arr,int t,int r){
    for (int i = 0; i < 9; i++)
    {
        int temp = arr[9 * t + i];
        arr[9 * t + i] = arr[9 * r + i];
        arr[9 * r + i] = temp;
    }

}

int main(){
    int arr[27];
    for (int i = 0; i < 27; i++)
    {
        arr[i]=i+1;
    }
    replace(arr,1,2);
    for (int i = 0; i < 27; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}




