#include <iostream>
#include <queue>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{
    cout << "enter the data: " << endl;
    int data;
    cin >> data;
    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }
    cout << "enter data to insert in left" << endl;
    root->left = buildTree(root->left);
    cout << "enter the data to insert in right" << endl;
    root->right = buildTree(root->right);
    return root;
}
int maxheight(node *root)
{
    node *temp = root;
    if ((temp == NULL))
    {
        return 0;
    }
    int len1 = maxheight(temp->left);
    int len2 = maxheight(temp->right);

    if (len1 > len2)
    {
        return (len1 + 1);
    }
    else
        return (len2 + 1);
}
void levelOrderTraversal(node *root)
{
    queue<node *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}
void buildtreelevelorder(node *&root)
{
    queue<node *> q;
    cout << "enter the data for root" << endl;
    int data;
    cin >> data;
    root = new node(data);
    q.push(root);
    while (!q.empty())
    {
        node *temp = q.front();
        q.pop();
        cout << "enter the left node for" << temp->data << endl;
        int leftdata;
        cin >> leftdata;
        if (leftdata != -1)
        {
            temp->left = new node(leftdata);
            q.push(temp->left);
        }
        cout << "enter the right node for" << temp->data << endl;
        int rightdata;
        cin >> rightdata;
        if (rightdata != -1)
        {
            temp->right = new node(rightdata);
            q.push(temp->right);
        }
    }
}
int main()
{
    node *root = NULL;
    // buildtreelevelorder(root);
    // levelOrderTraversal(root);
    // cout<<endl<<maxheight(root)<<endl;
    root = buildTree(root);
     //4 5 6 8 -1 -1 -1 7 -1 9 -1 -1 10 1 2 -1 -1 -1 3 -1 4 -1 -1
     levelOrderTraversal(root);
     cout << "height pf the tree: " << maxheight(root) << endl;
     cout << "inorder traversal: " << endl;
     inorder(root);
     cout << endl
          << "preorder traversal: " << endl;
     preorder(root);
     cout << endl
          << "postorder traversal: " << endl;
     postorder(root);

    return 0;
}