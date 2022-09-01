#include <iostream>
using namespace std;

/*kindly use ^ in place of ˆ since my local and also online
 compiler was not considering ˆ as a character*/
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
int preced(char c)
{
    switch (c)
    {
    case '+':
        return 1;
        break;
    case '-':
        return 1;
        break;
    case '*':
        return 2;
        break;
    case '/':
        return 2;
        break;
    case '^':
        return 3;
        break;
    default:
        return -1;
        break;
    }
}

float calculator(float val1, float val2, char s)
{
    if (s == '+')
    {
        return val1 + val2;
    }
    else if (s == '-')
    {
        return val1 - val2;
    }
    else if (s == '*')
    {
        return val1 * val2;
    }
    else if (s == '/')
    {
        return val1 / val2;
    }
}

int isOperator(char c)
{
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
    {
        return 1;
    }
    return 0;
}

float round(float x)
{
    int flag = 0;
    if (x < 0)
    {
        x = x * (-1);
        flag = 1;
    }
    int temp = x * 100;

    if (((x * 100) - temp) >= 0.5)
    {
        temp += 1;
    }

    float out = (float)temp / 100;

    if (flag)
    {
        return (-1) * out;
    }
    return out;
}

float evaluate(string s)
{
    Stack<float> operand_st;
    string concat = "";
    string out = "";

    int i = 0;

    for (int i = 0; s[i] != '\0'; i++)
    {

        // cout<<precedence(s[i])<<" ";
        if (s[i] == ',')
        {
            if (concat != "")
            {

                operand_st.push(stof(concat));
                concat = "";
            }
        }
        else if (!isOperator(s[i]))
        {
            if (
                ('0' <= s[i] && '9' >= s[i]))
            {

                concat += s[i];
            }
            else
            {
                cout << "wrong input" << endl;
                return -1;
            }
        }
        else
        {
            if (concat != "")
            {
                cout << "wrong input" << endl;
                return -1;
            }

            if (s[i] == '^')
            {
                if (operand_st.empty())
                {
                    cout << "wrong input" << endl;
                    return -1;
                }
                float op1 = operand_st.top();
                operand_st.pop();
                operand_st.push(op1 * op1);
            }
            else
            {
                if (operand_st.size() < 2)
                {
                    cout << "wrong input" << endl;
                    return -1;
                }

                float op1 = operand_st.top();
                operand_st.pop();
                float op2 = operand_st.top();
                operand_st.pop();
                operand_st.push(calculator(op2, op1, s[i]));
            }
        }
    }
    if (operand_st.size() != 1 || concat != "")
    {
        cout << "wrong input" << endl;
        return -1;
    }
    return (round(operand_st.top()));
};

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << evaluate(s) << endl;

    return 0;
}