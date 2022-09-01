#include <iostream>


using namespace std;

# define INT_MAX 100

class Stack
{
    char arr[INT_MAX];
    int _top;

public:
    Stack() : _top(-1) {}

    void push(char x)
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

    char top()
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

bool isOpeningBracket(char s){
    if(s=='{'|| s=='[' || s=='('){
        return true;
    }
    return false;
}

bool isClosingBracket(char s){
    if(s=='}'|| s==']' || s==')'){
        return true;
    }
    return false;
}

char pairOf(char s){
    if(isOpeningBracket(s)){
        if(s=='{') return '}';
        else if(s=='[') return ']';
        else return ')';
    }
}

bool isBalanced(string s)
{
    

    Stack st;
    for (int i = 0; i < s.size(); i++)
    {
        if (isOpeningBracket(s[i]))
        {
            st.push(s[i]);
            
            
        }
        else if(! st.empty()  && pairOf(st.top())==s[i]){
            st.pop();
            
        }
        else{
            return 0;
        }
    }
    if(! st.empty()){
        return 0;
    }
    return 1;
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin>>s;
    cout<<isBalanced(s)<<endl;
    return 0;
}