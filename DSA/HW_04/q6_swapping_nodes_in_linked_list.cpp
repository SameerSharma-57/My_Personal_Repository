#include <iostream>
using namespace std;
typedef struct Node
{
    int data;

    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
} Node;
Node *insertAtEnd(Node *end, int x)
{
    Node *n = new Node(x);
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
    Node* head=NULL;
    int temp;
    cin>>temp;
    head=new Node(temp);
    Node* end=head;
    for (int i = 0; i < n-1; i++)
    {
        cin>>temp;
        end=insertAtEnd(end,temp);
    }
    end=head;
    for (int i = 0; i < n; i++)
    {
        cout<<end->data<<" ";
        end=end->next;
    }
    cout<<endl;
    int p,q;
    cin>>p>>q;
    if(p>n||q>n||p>q){
        cout<<-1;
    }
    else{
        Node* p1=head;
        for (int i = 1; i < p; i++)
        {
            p1=p1->next;
        }
        Node* p2=head;
        for (int i = 1; i < q; i++)
        {
            p2=p2->next;
        }
        int temp=p1->data;
        p1->data=p2->data;
        p2->data=temp;

        for (int i = 0; i < n; i++)
        {
            cout<<head->data<<" ";
            head=head->next;
        }
        
        
        
    }
    
    

    return 0;
}