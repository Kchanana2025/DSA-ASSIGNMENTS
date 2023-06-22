#include <iostream>
using namespace std;
void binary(int arr[], int n)
{
    int mid;
    int key;
    int start = 0;
    int end = n - 1;
    int flag = 0;
    cout << "ENTER ELEMENT TO BE SEARCHED";
    cin >> key;
    while (start <= end)
    {
        mid = ((start + end) / 2);
        if (arr[mid] == key)
        {
            flag = 1;
            break;
        }

        else if (key > arr[mid])
        {
            start = mid + 1;
            flag = 0;
        }
        else
            end = n - 1;
        flag = 0;
    }
    if (flag == 1)
    {
        cout << "ELEMENT FOUND AT " << mid << "th INDEX";
    }
    else
        cout << "ELEMENT NOT FOUND";
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
    binary(arr, n);

    return 0;
}