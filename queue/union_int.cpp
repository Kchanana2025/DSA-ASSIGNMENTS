#include <iostream>
using namespace std;
class queue
{
    int size;
    int capacity;
    int *data;
    int startindex;
    int nextindex;

public:
    queue(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        data = new int[capacity];
        startindex = -1;
        nextindex = 0;
    }
    bool isempty()
    {
        return size == 0;
    }

    int getsize()
    {
        return size;
    }
    void enqueue(int ele)
    {
        if (size == capacity)
        {
            cout << "overflow";
        }
        data[nextindex] = ele;
        if (isempty())
            startindex = 0;
        nextindex = (nextindex + 1) % capacity;
        size++;
    }
    void dequeue()
    {
        if (isempty())
            cout << "underflow";
        startindex = (startindex + 1) % capacity;
        size--;
    }
    int front()
    {
        if (isempty())
        {
            cout << "underflow";
            return 0;
        }
        return data[startindex];
    }
    void intersection(queue Q2)
    {
        int k = 0;
        int arr[30];
        int size_1 = getsize();
        int size_2 = Q2.getsize();
        for (int i = 1; i <= size_1; i++)
        {
            int x = front();
            dequeue();
            for (int j = 1; j <= size_2; j++)
            {
                int y = Q2.front();
                Q2.dequeue();
                Q2.enqueue(y);
                if (x == y)
                {
                    arr[k] = x;
                    k++;
                }
            }
        }
        for (int i = 0; i < 3; i++)
            cout << arr[i];
        cout << endl;
    }
    void union_1(queue Q2)
    {
        int arr[30];
        int k = 0;
        int size_1 = getsize();
        while (size_1)
        {
            arr[k] = front();
            dequeue();
            // enqueue(arr[k]);

            size_1--;
            k++;
        }
        // for (int i = 0; i < 3; i++)
        //     cout << arr[i];

        int size_2 = Q2.getsize();
        while (size_2)
        {
            int flag = 0;
            int x = Q2.front();
            enqueue(x);
            dequeue();
            size_2--;
            int size_3 = k;
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
        for (int i = 0; i < 3; i++)
            cout << arr[i];
    }
};
int main()
{
    queue Q(10);
    queue Q2(10);
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    Q2.enqueue(10);
    Q2.enqueue(20);
    Q2.enqueue(30);
    queue Q3(Q);
    Q.intersection(Q2);
    Q3.union_1(Q2);
}