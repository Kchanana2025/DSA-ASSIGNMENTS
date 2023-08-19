// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
void Selectionsort(int *arr, int n)
{
    for (int i = 0; i <= n - 2; i++) // i takes care of ki konsa round chl rha hai
    {
        int minindex = i, min = arr[i];
        for (int j = i + 1; j <= n - 1; j++) // j takes care of finding the minimum element
        {
            if (arr[j] < min) // use > for descending order
            {
                min = arr[j];
                minindex = j;
            }
        }
        swap(arr[i], arr[minindex]);
    }
}
int main()
{
    int x;
    int arr[30];
    int n;
    cout << "ENTER THE SIZE OF THE ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    Selectionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
