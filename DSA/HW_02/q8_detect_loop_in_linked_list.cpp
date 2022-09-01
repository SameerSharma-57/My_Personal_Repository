#include <iostream>
using namespace std;
/*Driver code starts*/
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

void loopHere(Node *head, Node *tail, int position)
{
    if (position == 0)
        return;
    Node *walk = head;
    int i = 0;
    while (i < position - 1)
    {
        walk = walk->next;
        i++;
    }
    // cout<<walk->data<<'\n';
    tail->next = walk;
}
/*Driver code ends*/

Node *solve(Node *head)
{
    

    if (head == nullptr || head->next==nullptr)
    {
        return head;
    }

    Node *slow = head;
    Node *fast = head;
    while (fast!=nullptr && fast->next!=nullptr)
    {
        fast = fast->next->next;
        slow = slow->next;
        if (slow == fast)
        { 
            break;
        }
    }
    if (slow==fast)
    {
        slow=head;
        while (slow != fast)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        while(fast->next!=slow){
            fast=fast->next;
        }
        // cout<<fast->data<<" ";
        // cout<<fast->next->data<<" "<<slow->data<<endl;
        
        Node* temp=fast;
        
        while(slow!=fast){
            temp=insert(temp,slow->data);
            slow=slow->next;


        }
        temp=insert(temp,slow->data);

        
    }
    return head;

    // your code goes here
}

/*Driver code starts*/
int main()
{
    #ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    Node *head = new Node;
    int temp;
    cin >> temp;
    head->data = temp;
    head->next = NULL;
    Node *end = head;
    for (int i = 1; i < n; i++)
    {
        cin >> temp;
        end = insert(end, temp);
    }

    int position;
    cin >> position;
    loopHere(head, end, position);

    head = solve(head);
    Node *ptr = head;

    while (ptr)
    {
        cout << ptr->data << ' ';
        ptr = ptr->next;
    }
}
/*Driver code ends*/