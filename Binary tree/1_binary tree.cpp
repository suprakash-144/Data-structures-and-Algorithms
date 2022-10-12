#include <bits/stdc++.h>
#include <iostream>

using namespace std;
class node
{
private:
    /* data */
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
    else if (root->data < data)
    {
        insert(root->left, data);
    }
    else
    {
        insert(root->right, data);
    }
}
int main()
{
    node *root = NULL;
    int size, data;
    cout << "Enter the number of eleemts to insert: ";
    cin >> size;
    cout << "Enter the elements of the tree: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        insert(root, data);
    }

    return 0;
}
