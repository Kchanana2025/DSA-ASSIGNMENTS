#include <iostream>
using namespace std;
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (int i = 0; i < n - 1; i++) // for no of passes because in array of size n ,n-1 passes happen
    {
        swapped = false;
        for (int j = 0; j < n - i - 1; j++)
        { // for traversal of elements
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
        {
            break; // this means the array is sorted and there is no point of checking other passes
        }
    }
}
int main()
{
    int n;
    int arr[30];
    cout << "ENTER THE SIZE OF ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    bubbleSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}