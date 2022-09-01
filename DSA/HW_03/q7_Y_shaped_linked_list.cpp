#include <iostream>
using namespace std;
// / Driver code starts /
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
// 3 8 9 12 5 89 
// / Driver code ends /
Node * common_point(Node* head1,Node* head2){
    Node* temp1=head1;
    Node* temp2=head2;
    while(temp1){
        temp2=head2;
        while(temp2){
            if(temp1==temp2){
                return temp2;
            }
            temp2=temp2->next;
        }
        temp1=temp1->next;
    }
    return NULL;
}

Node *solve(Node *head1, Node *head2, int n, int m)
{
    Node* common= common_point(head1,head2);
    Node* big;
    Node* small;
    if (n>m)
    {
        big=head1;
        small=head2;
    }
    else{
        big=head2;
        small=head1;
    }
    Node* temp=big;
    while (temp->next!=common)
    {
        temp=temp->next;
    }
    temp->next=small;
    head1=big;
    return head1;

    
    

    // your code goes here
    
}

//  Driver code starts /
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
    int n, m;
    cin >> n >> m;
    int commonElements;
    cin >> commonElements;

    Node *head1 = NULL;
    Node *end1 = NULL;

    int temp;
    cin >> temp;
    head1 = new Node(temp);
    end1 = head1;
    for (int i = 1; i < n - commonElements; i++)
    {
        cin >> temp;
        end1 = insertAtEnd(end1, temp);
    }
    cin >> temp;

    Node *head2 = NULL;
    Node *end2 = NULL;
    head2 = new Node(temp);
    end2 = head2;

    for (int i = 1; i < m - commonElements; i++)
    {
        cin >> temp;
        end2 = insertAtEnd(end2, temp);
    }

    for (int i = 0; i < commonElements; i++)
    {
        cin >> temp;
        Node *temp1 = new Node(temp);
        end1->next = temp1;
        end1 = temp1;
        end2->next = temp1;
        end2 = temp1;
    }

    Node *head = solve(head1, head2, n, m);
    while (head)
    {
        cout << head->data << " ";
        head = head->next;
    }

    return 0;
}
// / Driver code ends /

