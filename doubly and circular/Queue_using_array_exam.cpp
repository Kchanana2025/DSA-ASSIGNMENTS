#define MAX 100
#include <iostream>
using namespace std;
class QueueUsingArray
{
    int front; // hmara alga element kahan jaake place hoga
    int rear;  // queue mein sbse phla element konsa rakha hua hai
    int arr[MAX];

public:
    QueueUsingArray()
    {
        front = -1;
        rear = -1;
    }
    int size()
    {
        int size = rear - front + 1;
        return size;
    }

    bool isEmpty()
    {
        if (front == -1 || front > rear)
        {
            return true;
        }
        return false;
    }
    bool isfull()
    {
        if (rear == MAX - 1)
        {
            cout << "Queue is full";
            return true;
        }
        return false;
    }
    int front_ele()
    {
        if (isEmpty())
        {
            cout << "EMPTY";
            return INT_MIN;
        }
        else
        {
            return arr[front];
        }
    }
    // insert element
    void enqueue(int element)
    {
        if (isfull()) // LAST INDEX PAR PAHUCH CHUKA HAI
        {
            cout << "Queue is full" << endl;
        }
        else
        {

            if (isEmpty()) // phla element dalne jaa rhe ho
            {
                front = 0;
                rear = 0;
            }
            else
            {
                rear++;
            }
            arr[rear] = element;
        }
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
    void dequeue()
    {
        if (isEmpty()) // front=-1 means abhi queue bharna hi start nai hui aur front>rear means dequeue kr krke queue isempty now
        {
            cout << "Queue is empty";
        }
        else
        {
            int ans = arr[front];
            front++;
        }
    }
    void print()
    {
        for (int i = front; i <= rear; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "endl";
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
    s.dequeue();
    s.dequeue();
    s.dequeue();
    return 0;
}