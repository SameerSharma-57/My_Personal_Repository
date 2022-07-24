# include  <iostream>
using namespace std;
 
int main()
{
    int n ;
    cin>>n;
    
    
    double a[n];
    
    cout<<"Enter the array"<<endl;
    for (int i = 0; i < n; i++)
    {
        cin>>a[i];
        /* code */
    }
    for (int i=0; i<n; i++){
    	cout<<a[i]<<" ";
	}
    cout<<endl;
    long max=a[0];
    for (int i = 0; i < n; i++)
    {

        if (max<a[i]){
            max=a[i];
 
        }


    }
    cout<<max<<endl;
    

    return 0;
}
