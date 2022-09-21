#include <iostream>

using namespace std;

void bubble_sort(int arr[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[20], size;
    cout << "Enter the size of the array: ";
    cin >> size;
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    cout << endl;
    bubble_sort(arr, size);
    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    return 0;
}
