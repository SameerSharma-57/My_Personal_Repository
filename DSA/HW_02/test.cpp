#include <iostream>
# include <vector>
using namespace std;

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n;
    cin>>n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        int val;
        cin>>val;
        v[i]=val;
    }
    for (int i = 0; i < n; i++)
    {
        cout<<v[i]<<endl;
    }
    
    
    return 0;
}