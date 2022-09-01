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
};

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    Stack<int> st;
    st.push(3);
    cout<<st.top();
    Stack<string> st1;
    st1.push("sameer");
    cout<<st1.top();
    return 0;
}