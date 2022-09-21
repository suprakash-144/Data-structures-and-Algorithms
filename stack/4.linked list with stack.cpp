#include <iostream>
#include <stdlib.h>
#include <stack>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL;
void traverse()
{
    node *ptr = top;
    cout << "The linked list is: \n";
    while (ptr)
    {
        cout << "The element is: " << ptr->data << endl;
        ptr = ptr->next;
    }
}
void push(int data)
{
    node *newnode = new node;
    newnode->data = data;
    if (newnode == NULL)
    {
        cout << "no memory";
        return;
    }
    newnode->next = top;
    top = newnode;
}
void pop()
{
    node *ptr = top;
    node *ptr1 = top->next;
    while (ptr1->next != NULL)
    {
        ptr = ptr->next;
        ptr1 = ptr1->next;
    }
    ptr->next = NULL;
    free(ptr1);
}
int main()
{
    int size, data;
    cout << "Enter the size of the list: ";
    cin >> size;
    cout << "Enter the elements of the list: ";
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        push(data);
    }
    traverse();
    return 0;
}
