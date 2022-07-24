#include <iostream>
#include <string>
# include <typeinfo>

using namespace std;
void add_strings(char s1[], char s2[])
{
    
    char *p = s1;
    char *q = s2;
    while (*p)
    {
        *p++;
    }
    while (*q)
    {
        *p = *q;
        
        *p++;
        *q++;
    }
   
    *p='\0';
    
    
}
int main()
{
    const int max = 100;
    char s1[max];
    
    cout << "enter the first string" << endl;
    cin>>s1;
    
    char s2[max];
    
    cout<<"enter the second string"<<endl;
    cin>>s2;
     
    
    add_strings(s1,s2);
    int i=0;
    cout<<s1;

    return 0;
}