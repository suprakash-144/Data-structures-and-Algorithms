#include <iostream>
#include <stdlib.h>

using namespace std;
int front = -1;
int rear = -1;
bool isfull(int a[])
{
    if (rear == (sizeof(a) - 1))
    {
        return true;
    }
    return false;
}

bool isempty()
{
    if (rear == -1 and front == -1)
    {
        return true;
    }
    return false;
}
void emque(int a[], int data)
{
    if (isfull(a))
    {
        return;
    }
    else if (isempty())
    {
        front = rear = 0;
    }
    else
    {
        rear += 1;
    }
    a[rear] = data;
}
int deque(int a[])
{
    if (isempty())
    {
        return -1;
    }
    else
    {
        return a[front++];
    }
}
int peek(int a[])
{
    return a[rear];
}
int main()
{
    int a[20];
    return 0;
}
