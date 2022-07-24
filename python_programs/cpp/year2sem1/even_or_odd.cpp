# include <iostream>
using namespace std;
 
int main(){
    double test =0;
    cout<<"Enter the number to test whether it is even or odd"<<endl;
    cin>>test;
    if (test==(int)test){
        
        if ((int)test%2==0)
        {
            cout<<test<<" is even"<<endl;
        }
        else{
            cout<<test<<" is odd"<<endl;
        }
    }
    else{
        cout<<"Please enter a valid integer"<<endl;
    }
     return 0;
}