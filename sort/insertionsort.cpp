#include <iostream>
using namespace std;
void insertionSort(int *arr, int n)
{
    int i = 1;
    int j;
    int temp;
    while (i < n)
    {
        while (j >= 0)
        {
            temp = arr[i];
            j = i - 1;
            if (arr[j] > temp)
                arr[j + 1] = arr[j];
        }
        arr[j + 1] = temp;
        i++;
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
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}