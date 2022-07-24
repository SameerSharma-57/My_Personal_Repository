# include <iostream>
# include <string.h>
using namespace std;

int main(){
    string s;
    cout<<"enter the string"<<endl;
    getline(cin,s);
    int cnt=0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i]=='a'|| s[i]=='e'|| s[i]=='i'|| s[i]=='o'|| s[i]=='u')
        {
            cnt++;
        }
        
    }
    
    cout<<cnt<<endl;
    return 0;
}