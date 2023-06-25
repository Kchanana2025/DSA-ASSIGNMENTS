//  Design the logic to remove the duplicate elements from an Array and after the
// deletionthearrayshould contain the uniqueelements.
#include <iostream>
using namespace std;
int remove_duplicates(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] == arr[j]) // if ke aage == lgta hai
            {
                while (j < n - 1)
                {
                    arr[j] = arr[j + 1];
                    j++;
                }
                n--;
                j = i;
                // j=i lene ka ye faida hai ki jab while loop se bahar aa jayega to next iteration me j++ hone se pahle j=i kar do qki jab j++ hoga to automatic j=i+1 ho jaayega aur phir ye current iterator dobara ho jayega required for cases like 1 2 2 2 2

                // j=temp ke index ko phle jaisa kr dia taki andar wala loop poora chl ske because 2 se zyada similar elements bhi toh ho skte thee
                // eg 5 1 5 3 5 toh agar hum j ko dubara reinitialize na krte toh sirf ek duplicacy jati aur 5 1 3 5 final output aa jata pr.hm temp=j krke loop normal chalate(kyunki j =n-2 yani n-2 index pr na pahucha hota) lekin j=i krke hmne ye iterator bhi dobara chala di
            }
        }
    }
    return n;
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
    n = remove_duplicates(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}