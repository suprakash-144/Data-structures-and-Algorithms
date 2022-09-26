#include <stdlib.h>
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
node *root = NULL;
node *newnode(int data)
{
    node *newnode = new node();
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
void insert(node *root, int data)
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
int hegiht(node *root)
{
    if (root == NULL)
    {
        return -1;
        // if we conside the highet as number of nodes then return 0
        // if we consider height as number of edges from the root then return -1
    }
    return max(hegiht(root->left), hegiht(root->right)) + 1;
}
int main()
{
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
