#include <iostream>
using namespace std;

typedef struct Node
{
    int data;
    Node *next;

} Node;

Node *insert(Node *end, int val)
{
    Node *n = new Node;
    n->data = val;
    n->next = NULL;
    end->next = n;
    return n;
}

int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    Node* head = new Node;
    int temp;
    cin>>temp;
    head->data=temp;
    head->next=NULL;
    Node* end=head;
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        end=insert(end,temp);
    }
    Node* fast=head;
    Node* slow=head;
    while(fast && fast->next){
        fast=fast->next->next;
        slow=slow->next;
    }
    cout<<slow->data<<endl;
    

    return 0;
}