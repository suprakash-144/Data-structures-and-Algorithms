#include <iostream>
#include <stdlib.h>

using namespace std;
int array[100];
void push(int i, int data)
{
    array[i] = data;
}
void print(int size)
{
    cout << "The array is :" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << "\t";
    }
    cout << "\n";
}
int pop(int size)
{
    return (size - 1);
}
int main()
{
    int data, size;
    string s;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> data;
        push(i, data);
    }
    print(size);
    cout << "Enter yes to  delete element: ";
    cin >> s;
    if (s == "yes")
    {
        size = pop(size);
        print(size);
    }

    return 0;
}
