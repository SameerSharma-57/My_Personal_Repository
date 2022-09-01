#include <iostream>
using namespace std;

class BST
{
private:
    int data;
    BST *left;
    BST *right;

public:
    BST() {}
    BST(int d) : data(d), left(NULL), right(NULL) {}
    BST *insert(BST *root, int d)
    {
        if (root == NULL)
        {
            return new BST(d);
        }

        if (d > root->data)
        {
            root->right = insert(root->right, d);
        }
        else
        {
            root->left = insert(root->left, d);
        }
        return root;
    }

    bool search(BST *root, int val)
    {
        if (root == NULL)
        {
            return 0;
        }
        else if (root->data < val)
        {
            return search(root->right, val);
        }
        else if (root->data > val)
        {
            return search(root->left, val);
        }
        return 1;
    }

    void pathToNode(BST *root, int val, int flag = 0)
    {

        if (!search(root, val))
        {
            cout << "-1" << endl;
            return;
        }
        cout << root->data << " ";
        if (root->data == val)
        {
            cout << endl;
            return;
        }
        else if (root->data > val)
        {
            return pathToNode(root->left, val);
        }
        return pathToNode(root->right, val);
    }
};
int main()
{
#ifndef ONLINE_MODE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    BST b;
    BST *root = NULL;
    int n, q;
    cin >> n >> q;
    int temp, x;
    cin >> temp;
    root = b.insert(root, temp);
    for (int i = 0; i < n - 1; i++)
    {
        cin >> temp;
        b.insert(root, temp);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> x;
        b.pathToNode(root, x, 1);
    }

    return 0;
}