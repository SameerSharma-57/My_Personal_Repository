# include <iostream>

using namespace std;
int main(){
    int q;
    cin>>q;
    for (int i = 0; i < q; i++)
    {
        int n,l,r;
        cin>>n>>l>>r;
        if (n<=r-l+1)
        {
            int val = l;
            cout<<"Yes"<<endl;
            for (int j = 0; j < n; j++)
            {
                cout<<val<<" ";
                val++;
            }
            cout<<endl;
            
        }
        else{
            cout<<"No"<<endl;
        }
        
    }
    
}
