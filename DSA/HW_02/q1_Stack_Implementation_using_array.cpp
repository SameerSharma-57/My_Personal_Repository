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

    void peek()
    {
        if (top < 0)
        {
            cout << "-1" << endl;
            return;
        }
        cout << arr[top] << endl;
    }

    void size()
    {
        cout << top + 1 << endl;
    }

    void isempty()
    {
        if (top < 0)
        {
            cout << 1 << endl;
            return ;
        }
        cout << 0 << endl;
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int cases;
    Stack stack;
    cin >> cases;
    for (int i = 0; i < cases; i++)
    {
        string func;
        cin >> func;

        // cout<<(func=="push")<<endl;

        if (func == "push")
        {

            int val;
            cin >> val;

            stack.push(val);
        }

        else if (func == "pop")
        {
            stack.pop();
        }

        else if (func == "peek")
        {
            stack.peek();
        }

        else if (func == "size")
        {
            stack.size();
        }

        else if (func == "isempty")
        {
            stack.isempty();
        }
    }

    return 0;
}