// reverse the elements of an array
#include <iostream>
using namespace std;
void missing(int *arr, int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        if (arr[i + 1] - arr[i] != 1)
        {
            cout << "missing no is" << arr[i] + 1;
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
    missing(arr, n);

    return 0;
}