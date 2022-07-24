# include <iostream>
# include <string.h>

using namespace std;
 
int main(){
    string stringin;
    string out="";
    getline(cin,stringin);
    for (int i = 0; i < stringin.length(); i++)
    {
        out=stringin[i]+out;
    }
    cout<<out;

    


    
    


    

    
    



    return 0;
}