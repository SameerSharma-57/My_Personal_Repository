# include <iostream>
using namespace std;


void swap(double arr[],int i,int j){
    double temp=*(arr+i);
    *(arr+i)=*(arr+j);
    *(arr+j)=temp;
}
int main(){
    int n;
    cout<<"enter the length of array"<<endl;
    cin>>n;
    cout<<"enter the array"<<endl;
    double arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    int i,j;
    cout<<"enter i and j"<<endl;
    cin>>i>>j;
    swap(arr,i,j);
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    

    return 0;
}
