// O(nlogn)
// O(n)
#include <iostream>
using namespace std;
// I made this entire function wrong
void merge(int *arr, int si, int mid, int ei)
{
    int arr1[30];
    //   int size1=mid-si+1;//NO need
    //   int size2=ei-mid;
    int i = si;
    int j = mid + 1;
    int k = 0;
    while (i <= mid && j <= ei)
    {
        if (arr[i] <= arr[j])
        {
            arr1[k] = arr[i];
            i++;
            k++;
        }
        else if (arr[i] > arr[j])
        {
            arr1[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= mid)
    {
        arr1[k] = arr[i];
        i++;
        k++;
    }
    while (j <= ei)
    {
        arr1[k] = arr[j];
        j++;
        k++;
    }
    int t = 0; // i did this wrong
    for (int i = si; i <= ei; i++)
    {
        arr[i] = arr1[t++];
    }
}
void merge_sort(int *arr, int si, int ei)
{

    if (si >= ei) // si>=ei hai yaad rakio
        return;

    int mid = (si + ei) / 2;
    merge_sort(arr, si, mid);
    merge_sort(arr, mid + 1, ei);
    merge(arr, si, mid, ei);
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
    int si = 0;
    int ei = n - 1;
    merge_sort(arr, si, ei);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
