#include <iostream>
using namespace std;
void insertion_sort(int a[], int size)
{

    for (int i = 1; i < size; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (temp <= a[j])
        {
            swap(a[j + 1], a[j]);
            j--;
        }
        a[j + 1] = temp;
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
    insertion_sort(arr, size);
    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    return 0;
}
