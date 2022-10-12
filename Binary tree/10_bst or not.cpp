
#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class node
{

public:
    int data;
    node *left;
    node *right;
};

node *newnode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void insert(node *&root, int data)
{
    if (root == NULL)
    {
        root = newnode(data);
        return;
    }
    else if (root->data > data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}
void inorder(node *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}
void bstornot(node *root)
{
    vector<int> ans;
    inorder(root, ans);
    for (int i = 0; i < ans.size() - 1; i++)
    {
        if (ans[i] > ans[i + 1])
        {
            cout << "Not a Binary search tree!!";
            return;
        }
    }
    cout << "It is a Binary search tree!!";
}
int main()
{
    node *root = new node();
    root = NULL;
    int size, data;
    cout << "Enter the number of eleemts to insert: ";
    cin >> size;
    cout << "Enter the elements of the tree: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        insert(root, data);
    }
    bstornot(root);

    return 0;
}
