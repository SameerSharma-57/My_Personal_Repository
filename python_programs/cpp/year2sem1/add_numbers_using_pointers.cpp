#include <iostream>
using namespace std;

double add_numbers_using_pointers(double *num1,double *num2){
    double out;
    out=*num1+*num2;
    return out;
}
int main()
{
    double n,m;
    cout<<"enter the two numbers to add"<<endl;
    cin>>n>>m;
    cout<<add_numbers_using_pointers(&n,&m)<<endl;


    return 0;
}