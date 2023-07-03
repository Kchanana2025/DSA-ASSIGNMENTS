#define MAX 100
int arr[MAX];
#include <iostream>
using namespace std;
class QueueUsingArray
{
    int front;    // hmara alga element kahan jaake place hoga
    int rear;     // queue mein sbse phla element konsa rakha hua hai
    int size;     // currenly size kitna hai
    int capacity; // total size of the queue (max kitne lements enter kr skte hain)(basically s jo hm input le rhe hain)
public:
    QueueUsingArray()
    {
        front = -1;
        rear = -1;
        size = 0;
    }

    // bool isEmpty()
    // {
    //     return size == 0;
    // }
    // insert element
    void enqueue(int element)
    {
        if (front == (rear + 1) % MAX) // LAST INDEX PAR PAHUCH CHUKA HAI
        {
            cout << "Queue is full" << endl;
            return;
        }
        rear = ((rear + 1) % MAX);
        arr[rear] = element;
        if (front == -1)
        {
            front = 0;
        }
        // size++;//no need
    }
    // int front()
    // {
    //     if (isEmpty())
    //     {
    //         cout << "Queue is empty";
    //         return 0;
    //     }
    //     return data[rear];
    // }
    int dequeue()
    {
        if (front == rear && rear == -1)
        {
            cout << "Queue is empty";
            return 0;
        }
        int ans = arr[front];
        if (front == rear) // not compulsary
        {
            rear = -1;
            front = -1;
        }
        else
        {
            front = ((front + 1) % capacity);
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray s;
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    cout << s.dequeue();
    cout << s.dequeue();
    cout << s.dequeue();
    return 0;
}