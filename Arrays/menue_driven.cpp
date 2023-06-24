//) Develop a Menu driven program to demonstrate the following operations of Arrays
// 1.CREATE
// 2.DISPLAY
// 3.INSERT
// 4.DELETE
// 5.SEARCH
// 6.EXIT

#include <iostream>
using namespace std;
int delete(int arr[], int n)
{
    int i;
    int j;
    if (n == 0)
    {
        cout << "ELEMENT CANT BE DELETED";
    }
    cout << "ENTER THE INDEX AT WHICH YOU WISH TO DELETE THE ELEMENT";
    cin >> j;
    for (int i = j; i < n; i++)
    {
        arr[i] = arr[i + 1];
    }
    return n - 1;
}

int create(int arr[]) // POPULATING THE ARRAY
{
    int n;
    cout << "ENTER THE SIZE OF ARRAY";
    cin >> n;
    cout << "ENTER THE ELEMENTS OF ARRAY";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    return n;
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i];
    }
}
int insert(int arr[30], int n)
{
    int j;
    int flag = 0;
    int i, val;
    // if(n==0)
    cout << "ENTER THE POSITION AT WHICH YOU WANT TO INSERT ELEMENT";
    cin >> j;
    cin >> val;
    for (i = n - 1; i >= j; i++)
    {
        arr[i + 1] = arr[i];
    }
    arr[j] = val;
    return n + 1;
}
void search(int *arr, int n)
{
    int m, i;
    int flag = 0;
    cout << "Enter element you wish to search";
    cin >> m;
    for (i = 0; i < n; i++)
    {
        if (arr[i] == m)
            flag = 1;
        break;
    }
    if (flag == 1)
        cout << "Element is presnt at " << i << "th"
             << "index";
    else
        cout << "element not present";
}

int main()
{
    int arr[30];
    int a;
    cout << "1.CREATE";
    cout << "2.DISPLAY";
    cout << "3.INSERT";
    cout << "4.DELETE";
    cout << "SEARCH";
    cout << "EXIT";
    cout << "ENTER YOUR CHOICE";
    cin >> a;
    switch (a)
    {
    case 1:
        int n = create(arr);
    case 2:
        display(arr, n);
    case 3:
        insert(arr, n);
    case 4:
        int n = delete (arr, n);
    case 5:
        search(arr, n);
    }
    return 0;
}