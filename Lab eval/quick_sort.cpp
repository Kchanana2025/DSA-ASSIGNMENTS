// O(nlogn)
// O(n)
// quick sort aur merge sort dono mein sirf start end ka use kro i size -1 ye sab mat ghusao
#include <iostream>
using namespace std;
int partition(int arr[], int start, int end) // return an index jiske left mein sare elements usse chote aur right mein sare uss se bde i.e it is at its right position
{
    int pivot = arr[start];
    int counter = 0;
    for (int i = start + 1; i <= end; i++)
    {
        if (arr[i] > pivot)
            counter++;
    }
    int pivotindex = start + counter;
    // swapped
    int temp = arr[start];
    arr[start] = arr[pivotindex];
    arr[pivotindex] = temp;
    int i = start;
    int j = end;
    while (i <= pivotindex - 1 && j >= pivotindex + 1) // remember this condition
    {
        while (i < pivotindex && arr[i] > pivot)
        { // pivot ayega idhar
            i++;
        }
        while (j > pivotindex && arr[j] < pivot) // pivot ayega idhar
            j--;

        while (i < pivotindex && j > pivotindex) // isme equal elements aur
        // wo wale elements jo pivot se chote hain aur aage bde and bde hain aur piche pde hain swap ho jayenge
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    return pivotindex;
}
void quick_sort(int *arr, int start, int end)
{
    if (start >= end)
        return;
    int pivotindex = partition(arr, start, end);
    quick_sort(arr, start, pivotindex - 1);
    quick_sort(arr, pivotindex + 1, end);
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
    quick_sort(arr, si, ei);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
