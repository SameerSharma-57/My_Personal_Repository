#include<iostream>
using namespace std;

typedef struct Node{
    int data;
    struct Node *next;

    Node (int x){
        data = x;
        next = NULL;
    }
}Node;

Node* checkpoint(Node* head1, Node* head2)
{
    while (head2) {
        Node* temp = head1;
        while (temp) {
            if (temp == head2)
                return head2;
            temp = temp->next;
        }
        head2 = head2->next;
    }
    return NULL;
}

Node *solve(Node *head1, Node *head2, int n, int m){
  //your code goes here
  Node* temp = checkpoint(head1,head2);
  Node* temp1;
  Node* temp2;
  if(n>m){
    temp1 = head1;
    temp2 = head2;
  }
  else{
    temp2 = head1;
    temp1 = head2;
  }
  Node* tempo = temp1;
  while(tempo->next != temp){
    tempo = tempo->next;
  }                     
  tempo->next = temp2;
  head1 = temp1;               
  return head1;
}


Node *insertAtEnd(Node *end,int x){
    Node *n=new Node(x);
    end->next=n;
    return n;
}
int main(){
    #ifndef ONLINE_MODE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n,m;cin>>n>>m;
    int commonElements;cin>>commonElements;

    Node *head1=NULL;
    Node *end1=NULL;

    int temp;cin>>temp;
    head1=new Node(temp);
    end1=head1;
    for(int i=1;i<n-commonElements;i++){
        cin>>temp;
        end1=insertAtEnd(end1,temp);
    }
    cin>>temp;
   
    Node *head2=NULL;
    Node *end2=NULL;
    head2=new Node(temp);
    end2=head2;

    for(int i=1;i<m-commonElements;i++){
        cin>>temp;
        end2=insertAtEnd(end2,temp);
    }


    for(int i=0;i<commonElements;i++){
        cin>>temp;
        Node *temp1=new Node(temp);
        end1->next=temp1;
        end1=temp1;
        end2->next=temp1;
        end2=temp1;
    }

    Node *head=solve(head1,head2,n,m);
    while (head)
    {
        cout<<head->data<<" ";
        head = head->next;
    }
    
    return 0;
}
