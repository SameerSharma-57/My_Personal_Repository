#include <iostream>

using namespace std;
#define INT_MAX 100
class Queue
{
    int arr[INT_MAX];
    int bck = -1;
    int frnt = 0;
    int currSize = 0;

public:
    bool empty()
    {
        if (currSize > 0)
        {
            return 0;
        }
        return 1;
    }
    void push(int x)
    {
        if (currSize <= INT_MAX)
        {
            bck++;
            if (bck >= INT_MAX)
            {
                bck = 0;
            }
            arr[bck] = x;
            currSize++;
            return;
        }
        cout << "overflow" << endl;
    }

    void pop()
    {
        if (!this->empty())
        {
            currSize--;
            frnt++;
            return;
        }
        cout << "queue is empty" << endl;
        return;
    }

    int front()
    {
        if (currSize>0)
        {
            
            return arr[frnt];
        }
        cout << -1 << endl;
    }

    int back()
    {
        if (!this->empty())
        {
            
            return arr[bck];
        }
        cout << -1 << endl;
    }

    int size()
    {
        return currSize;
    }

    void isempty()
    {
        cout << this->empty() << endl;
    }
};
class Stack
{
    Queue q,p;

public:
    void push(int x)
    {
        while(!q.empty()){
            p.push(q.front());
            q.pop();
        }
        q.push(x);
        while(!p.empty()){
            q.push(p.front());
            p.pop();

        }
        
    }

    void pop()
    {
        if (q.empty())
        {
            cout << "stack is empty" << endl;
            return;
        }
        q.pop();
        
    }

    void top()
    {
        if (q.empty())
        {
            cout << "-1" << endl;
            return;
        }
        cout << q.front() << endl;
    }

    void size()
    {
        cout << q.size() << endl;
    }

    void isempty()
    {
        if (q.empty())
        {
            cout << 1 << endl;
            return;
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

        else if (func == "top")
        {
            stack.top();
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