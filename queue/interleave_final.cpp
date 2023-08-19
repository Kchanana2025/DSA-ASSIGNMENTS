#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <typename T>
class queueusingarray
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
    void push(int ele)
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
void interleave(queue<int> &Q)
{
    if (Q.size() % 2 != 0)
    {
        cout << "input even elements";
        return;
    }
    stack<int> s;
    int halfsize = Q.size() / 2;

    for (int i = 0; i < halfsize; i++)
    {
        s.push(Q.front());
        Q.pop();
    }

    while (!s.empty())
    {
        Q.push(s.top());
        s.pop();
    }
    for (int i = 0; i < halfsize; i++)
    {
        Q.push(Q.front());
        Q.pop();
    }
    for (int i = 0; i < halfsize; i++)
    {
        s.push(Q.front());
        Q.pop();
    }
    while (!s.empty())
    {
        Q.push(s.top());
        s.pop();
        Q.push(Q.front());
        Q.pop();
    }
    while (Q.size())
    {
        cout << Q.front();
        Q.pop();
    }
}
int main()
{
    queue<int> Q;
    Q.push(10);
    Q.push(20);
    Q.push(30);
    Q.push(40);
    Q.push(50);
    Q.push(60);
    interleave(Q);
}