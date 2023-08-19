// this is optimized bubble sort in best case its time complexity is O(n)
//  worst:O(n^2)
#include <iostream>
using namespace std;
void inertionsort(int *arr, int n)
{
    for (int i = 1; i < n; i++) // we start from i=1 assuming first element is sorted
    {
        int j = i - 1;
        int temp = arr[i];
        while (j >= 0)
        {
            if (arr[j] > temp) // use < for descending
            {
                arr[j + 1] = arr[j];
                j--; // bhool mat jio ye krna
            }
            else
                break; // that means for this iteration left part of the array is sorted
        }
        arr[j + 1] = temp;
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
    inertionsort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
