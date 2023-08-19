// this is optimized bubble sort in best case its time complexity is O(n)
//  worst:O(n^2)
// average:O(n^2)
// this is optimized bubble sort in best case its time complexity is O(n)
// worst:O(n^2)
#include <iostream>
using namespace std;
void bubblesort(int *arr, int n)
{
    for (int i = 0; i <= n - 2; i++) // i is taking care of rounds
    {
        bool flag = false;
        for (int j = 0; j <= n - i - 2; j++) // j is taking care of traversal and swapping
        {
            if (arr[j] > arr[j + 1]) // use < for descending
            {
                swap(arr[j], arr[j + 1]); // dhang se swap krio
                flag = true;
            }
        }
        if (flag == false)
            break;
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
    bubblesort(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
