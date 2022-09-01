#include <iostream>


using namespace std;
# define long long int

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

    int n;
    cin >> n;
    Stack st;
    int v[INT_MAX];

    for (int i = 0; i < n; i++)
    {
        int val;
        cin >> val;
        v[i] = val;
    }

    int out[INT_MAX];

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            out[st.top()] = i;

            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        out[st.top()] = 0;
        st.pop();
    }

    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && v[st.top()] <= v[i])
        {
            out[st.top()] *= i;

            st.pop();
        }
        st.push(i);
    }
    while (!st.empty())
    {
        out[st.top()] *= 0;
        st.pop();
    }
    int max=out[0];
    for (int i = 0; i < n; i++)
    {
        if(max<out[i]){
            max=out[i];
        }
    }
    cout<<max<<endl;
    
    for (int i = 0; i < n; i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}