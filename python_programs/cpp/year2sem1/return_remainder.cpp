#include <iostream>
using namespace std;

int main()
{
    double divisor,dividend;
    cout<<"enter divisor"<<endl;
    cin>>divisor;
    cout<<"enter dividend"<<endl;
    cin>>dividend;
    if(divisor==0){
        cout<<"can't divide by zero";
        exit(0);
    }
    
    while (dividend>=divisor)
    {
        dividend-=divisor;
    }
    cout<<dividend;
    return 0;
}