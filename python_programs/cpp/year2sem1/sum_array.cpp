# include <iostream>
using namespace std;
void printarr(double arr[], int n){
    for (int i = 0; i <n; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}


int main(){
    int n1=3;
    int n2=5;
    double arr1[n1] ={0,0,0};
    double arr2[n2]={0,0,0,0,0};

    cout<<"Enter size of first array"<<endl;
    cin>>n1;
    cout<<"Enter first array"<<endl;
    for (int i = 0; i < n1; i++)
    {
        cin>>arr1[i];
    }
    // printarr(arr1,n1);
    cout<<"Enter size of second array"<<endl;
    cin>>n2;
    cout<<"Enter second array"<<endl;
    for (int i = 0; i < n2; i++)
    {
        cin>>arr2[i];
    }

    int n3=n1+n2;
    double arr[n3];
    for (int i = 0; i < n1; i++)
    {
        arr[i]=arr1[i];
    }
    // printarr(arr1,n1);
    for (int j = 0; j < n2; j++)
    {
        arr[n1+j]=arr2[j];
    }
    // printarr(arr1,n1);
    // printarr(arr2,n2);
    printarr(arr,n3);
    
    

    return 0;
         

}