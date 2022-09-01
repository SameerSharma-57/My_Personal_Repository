#include <iostream>
#include <cmath>
using namespace std;
typedef struct Node
{
    int pow, coeff;
    Node *next;

} Node;

Node *insert(Node *end, int p, int c)
{
    Node *n = new Node;
    n->pow = p;
    n->coeff = c;
    n->next = NULL;
    end->next = n;
    return n;
}
void input(Node *l, int n)
{
    int c1;
    cin >> c1;
    l->pow = n;
    l->coeff = c1;
    l->next = NULL;
    Node *temp = l;

    for (int i = n - 1; i >= 0; i--)
    {

        cin >> c1;
        temp = insert(temp, i, c1);
    }
}

long long eval(Node *l, int x)
{
    long long out = 0;
    Node *temp = l;
    while (temp)
    {
        out += (temp->coeff) * (pow(x, temp->pow));
        temp = temp->next;
    }
    return out;
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int cases;
    cin >> cases;
    for (int _ = 0; _ < cases; _++)
    {
        int n1, n2;
        cin >> n1 >> n2;
        Node *p1 = new Node;

        Node *p2 = new Node;

        input(p1, n1);
        input(p2, n2);

        int x;
        cin >> x;
        long long p1x = eval(p1, x);
        long long p2x = eval(p2, x);
        cout << p1x << " " << p2x << " "
             << (p1x + p2x) << " "
             << (5 * p2x) << endl;
    }

    return 0;
}