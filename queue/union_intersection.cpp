#include <iostream>
#include <queue>
using namespace std;

void intersection(queue<int> Q1, queue<int> Q2)
{
    int k = 0;
    int arr[30];
    while (!Q1.empty())
    {
        int size_2 = Q2.size();
        int temp = Q1.front();
        Q1.pop();

        while (size_2)
        {
            int y = Q2.front();
            Q2.push(y);
            Q2.pop();
            if (temp == y)
            {
                arr[k] = temp;
                k++;
            }
            size_2--;
        }
    }
    for (int i = 0; i < k; i++)
        cout << arr[i];
}
void union_1(queue<int> Q1, queue<int> Q2)
{
    int k = 0;
    int arr[30];
    int size_1 = Q1.size();
    int size_2 = Q2.size();

    while (size_1)
    {
        arr[k] = Q1.front();
        k++;
        size_1--;
        Q1.pop();
    }
    int size_3 = k;
    while (size_2)
    {
        int x = Q2.front();
        Q2.pop();
        int flag = 0;
        for (int i = 0; i < size_3; i++)
        {
            if (arr[i] == x)
            {

                flag = 1;
                break;
            }
        }
        if (flag == 0)
        {
            arr[k] = x;
            k++;
        }
        size_2--;
    }
    for (int i = 0; i < k; i++)
        cout << arr[i];
}
int main()
{
    queue<int> Q1;
    queue<int> Q2;
    Q1.push(10);
    Q1.push(20);
    Q1.push(30);
    Q2.push(10);
    Q2.push(20);
    Q2.push(30);
    intersection(Q1, Q2);
    union_1(Q1, Q2);
}