#include <iostream>
using namespace std;



# define INT_MAX 100

class Stack
{
    int arr[INT_MAX];
    int _top;

public:
    Stack() : _top(-1) {}

    void push(int x)
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

    int top()
    {
        if (_top < 0)
        {

            return -1;
        }
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
};

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    
    Stack st;
    int n;
    cin>>n;
    int arr[n];
    int out[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];

    }
    
    
    for (int i = 0; i < n; i++)
    {
        out[i]=1;
        while(!st.empty() && arr[i]>=arr[st.top()]){
            
            out[i]+=out[st.top()];
            st.pop();
        }
        st.push(i);
    }
    for (int i = 0; i < n; i++)
    {
        cout<<out[i]<<" ";
    }
    




    
    return 0;
}