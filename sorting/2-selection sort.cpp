#include <iostream>

using namespace std;

void selection_sort(int arr[], int size)
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[min] > arr[j])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
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
    selection_sort(arr, size);
    cout << "After sorting: ";
    for (int i = 0; i < size; i++)
    {
        cout << "\t" << arr[i];
    }
    return 0;
}
