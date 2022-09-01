#include <iostream>
using namespace std;
# define INT_MAX 100
template <class T>
class Stack
{
    T arr[INT_MAX];
    int _top;

public:
    Stack(): _top(-1) {}

    void push(T x)
    {
        arr[++_top] = x;
    }

    void pop()
    {
        if (_top < 0)
        {
            cout << "stack is empty" << endl;
            return;
        }
        _top--;
    }

    T top()
    {
        
        return arr[_top];
    }

    int size()
    {
        cout << _top + 1 << endl;
        return _top + 1;
    }

    bool empty()
    {
        if (_top < 0)
        {

            return true;
        }
        return false;
    }

    bool isPalindrome(string s){
        if(s.size()==0||s.size()==1){
            return 1;
        }
        Stack<char> st;
        int n;
        int flag=0;
        if(s.size()%2==0){
            n=s.size()/2;
        }
        else{
            n=(s.size()+1)/2;
            flag=1;
        }
        for (int i = 0; i < n; i++)
        {
            st.push(s[i]);
        }
        if (flag)
        {
            st.pop();
        }
        for (int i = n; i < s.size(); i++)
        {
            if(s[i]!=st.top()){
                return 0;
            }
            st.pop();
        }
        return 1;
        
        
        
        
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin>>s;
    Stack<char> st;
    cout<<st.isPalindrome(s);
    return 0;
}