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
class Queue
{
    Stack st1, st2;

public:
    void push(int x)
    {
        while (!st2.empty())
        {
            st1.push(st2.top());
            st2.pop();
        }

        st1.push(x);
        

    }

    void pop()
    {
        while (!st1.empty())
        {
            st2.push(st1.top());
            st1.pop();
        }
        
        if(st2.empty()){
            cout<<"empty"<<endl;
            return ;
        }
        cout<<st2.top()<<endl;
        st2.pop();
            
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cases;
    Queue queue;
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

            queue.push(val);
        }

        else if (func == "pop")
        {
            queue.pop();
        }

        
    }
    return 0;
}