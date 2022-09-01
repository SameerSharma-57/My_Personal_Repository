#include <iostream>
#include <stack>
using namespace std;
#define INT_MAX 100
template <class T>
class Stack
{
    T arr[INT_MAX];
    int _top;

public:
    Stack() : _top(-1) {}

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

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}
string solve(string s)
{
    Stack<string> operand_st;
    string concat = "";
    
    

    int i = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {

        // cout<<precedence(s[i])<<" ";
        if (s[i] == ',')
        {
            if (concat != "")
            {
                operand_st.push(concat);
                concat = "";
            }
        }
        else if (!isOperator(s[i]))
        {
            if (('a' <= s[i] && 'z' >= s[i]) ||
                ('A' <= s[i] && 'Z' >= s[i]) ||
                ('0' <= s[i] && '9' >= s[i]) )
            {

                concat += s[i];
            }
            else{
                return "wrong input";
            }
        }
        else
        {
            if (concat != "")
            {
                return "wrong input";
            }

            if (s[i] == '^')
            {
                if (operand_st.empty())
                {
                    return "wrong input";
                }
                string op1 = operand_st.top();
                operand_st.pop();
                operand_st.push("(" + op1 + s[i] + ")");
            }
            else
            {
                if (operand_st.size() < 2)
                {
                    return "wrong input";
                }

                string op1 = operand_st.top();
                operand_st.pop();
                string op2 = operand_st.top();
                operand_st.pop();
                operand_st.push("(" + op2 + s[i] + op1 + ")");
            }
        }
    }
    if (operand_st.size() != 1 || concat != "")
    {
        return "wrong input";
    }
    return operand_st.top();
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    cout << solve(s);

    return 0;
}