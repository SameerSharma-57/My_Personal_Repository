#include <iostream>

using namespace std;

#define INT_MAX 100
class Stack
{
    int arr[INT_MAX];
    int top;

public:
    Stack() : top(-1) {}

    void push(int x)
    {
        arr[++top] = x;
    }

    void pop()
    {
        if (top < 0)
        {
            cout << "stack is empty" << endl;
            return;
        }
        top--;
    }

    int peek()
    {
        if (top < 0)
        {

            return -1;
        }
        return arr[top];
    }

    int size()
    {
        cout << top + 1 << endl;
        return top + 1;
    }

    bool isempty()
    {
        if (top < 0)
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

    for (int i = 0; i < n; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    int out[INT_MAX];
    for (int i = 0; i < n; i++)
    {
        while (!st.isempty() && v[st.peek()] < v[i])
        {
            out[st.peek()] = (i - st.peek());

            st.pop();
        }
        st.push(i);
    }
    while (!st.isempty())
    {
        out[st.peek()] = 0;
        st.pop();
    }

    for (int i = 0; i < n; i++)
    {
        cout << out[i] << " ";
    }

    return 0;
}