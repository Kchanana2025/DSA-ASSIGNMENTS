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
};
int main()
{
    queue Q(10);
    Q.enqueue(10);
    Q.enqueue(20);
    Q.enqueue(30);
    cout << Q.front();
}