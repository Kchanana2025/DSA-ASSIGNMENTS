#include <iostream>
using namespace std;
#define MAX 100
class queueusingarray
{

    int data[MAX];
    int front;
    int rear;

public:
    queueusingarray()
    {
        front = -1;
        rear = -1;
    }

    int size()
    {
        return rear - front + 1;
    }
    bool isfull()
    {
        if (rear == MAX - 1)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if (front == -1 || front > rear)
            return true;
        else
            return false;
    }
    void enqueue(int element)
    {
        if (isempty())
        {
            front = 0;
            rear = 0;
            data[rear] = element;
        }
        else if (isfull())
        {
            cout << " overflow";
        }
        else
        {
            rear++;
            data[rear] = element;
        }
    }

    void dequeue()
    {
        if (isempty())
            cout << "underflow";

        else
        {
            front++;
        }
    }
    int peek()
    {
        if (isempty())
        {
            cout << "underflow";
            return 0;
        }
        else
            return data[front];
    }
};
int main()
{
    queueusingarray Q;
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    cout << Q.peek();

    return 0;
}