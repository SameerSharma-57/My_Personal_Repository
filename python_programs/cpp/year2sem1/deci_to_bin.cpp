#include <iostream>
using namespace std;

int main()
{
    int deci=0;
    cin>>deci;
    int bin[32];
    int ind=0;
    while(deci>0){
        bin[ind]=deci%2;
        deci=deci/2;
        ind++;

    }
    
    for (int i = ind-1; i>=0 ; i--)
    {
        cout<<bin[i];
    }
    cout<<endl;
    
    return 0;
}