#include <iostream>
using namespace std;


# define INT_MAX 100

class Stack
{
    int arr[INT_MAX];
    int _top;
    int min_arr[INT_MAX];
    int currSize =0;
    

public:
    
    Stack(): _top(-1), currSize(-1){}
    void push(int x)
    {
        arr[++_top] = x;
        if(currSize==-1){
            min_arr[++currSize]=x;
        }
        else if(x<min_arr[currSize]){
            min_arr[++currSize]=x;
        }
    }

    void pop()
    {
        if (_top < 0)
        {
            cout << "stack is empty" << endl;
            return;
        }
        if(arr[_top]==min_arr[currSize]){
            currSize--;
        }
        _top--;
    }

    int top()
    {
        if(_top==-1){
            return -1;
        }
        return arr[_top];
    }

    

    
    int getmin(){
        if(_top==0){
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        return min_arr[currSize];
    }
};

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int cases;
    Stack st;
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

            st.push(val);
        }

        else if (func == "pop")
        {
            st.pop();
        }

        else if (func == "top")
        {
            cout<<st.top()<<endl;
        }

        else if (func == "getmin")
        {
            cout<<st.getmin()<<endl;
        }

        
    }
    return 0;
}