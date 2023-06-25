// reverse the elements of an array
#include <iostream>
using namespace std;
void reverse(int *arr, int n)
{
    for (int i = 0, j = n - 1; i <= j; i++, j--)
    { // i<n/2 && j>=n/2 ya phir i<n/2 , j>=n/2 yaha and isliye lgaya hai kyunki dono mein se koi bhi condtion false ho jaye toh hmien bahar nikalna hai aisa isliye krna hai kyunki j odd no elements ke lie galat value achieve krega lekin hamien i baacha lega loop terminate krke

        swap(arr[i], arr[j]);
        // OR temp=arr[i];
        //  arr[i]=arr[j];
        //  arr[j]=temp;
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
    reverse(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}