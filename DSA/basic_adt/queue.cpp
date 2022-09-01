#include <iostream>
using namespace std;

#define INT_MAX 100
template <class T>
class Queue
{
    T arr[INT_MAX];
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
    void push(T x)
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

    T front()
    {

        return arr[frnt];
    }

    T back()
    {
        return arr[bck];
    }

    int size()
    {
        return currSize;
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    Queue<string> q;
    q.push("hello");
    q.push("world");
    cout << q.front() << endl
         << q.back() << endl; // q.push(3);
    // q.push(4);
    // cout<<q.front();
    return 0;
}