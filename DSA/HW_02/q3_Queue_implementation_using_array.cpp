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

    void front()
    {
        if (currSize>0)
        {
            cout << arr[frnt] << endl;
            return;
        }
        cout << -1 << endl;
    }

    void back()
    {
        if (!this->empty())
        {
            cout << arr[bck] << endl;
            return;
        }
        cout << -1 << endl;
    }

    void size()
    {
        cout << currSize << endl;
    }

    void isempty()
    {
        cout << this->empty() << endl;
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

        else if (func == "front")
        {
            queue.front();
        }
        else if (func == "back")
        {
            queue.back();
        }

        else if (func == "size")
        {
            queue.size();
        }

        else if (func == "isempty")
        {
            queue.isempty();
        }
    }

    return 0;
}