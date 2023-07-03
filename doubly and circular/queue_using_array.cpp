#include <iostream>
using namespace std;
class QueueUsingArray
{
    int *data;      // array
    int nextindex;  // hmara alga element kahan jaake place hoga
    int firstindex; // queue mein sbse phla element konsa rakha hua hai
    int size;       // currenly size kitna hai
    int capacity;   // total size of the queue (max kitne lements enter kr skte hain)(basically s jo hm input le rhe hain)
public:
    QueueUsingArray(int s) // s:size of queue (entered by user) (generally do cheezo ka naam same mt rakha kro agar rakh bhi skte ho jaise yaha rakh skte thee parameter ka naam bhi size(this pointer lgake constructor mein) pr hmne aviod kia )
    {
        data = new int[s];
        nextindex = 0;
        firstindex = -1;
        size = 0;
        capacity = s;
    }
    int getsize()
    {
        return size;
    }
    bool isEmpty()
    {
        return size == 0;
    }
    // insert element
    void enqueue(int element)
    {
        if (size == capacity)
        {
            cout << "Queue is full" << endl;
            return;
        }
        data[nextindex] = element;
        nextindex = ((nextindex + 1) % capacity);
        if (firstindex == -1)
        {
            firstindex = 0;
        }
        size++;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        return data[firstindex];
    }
    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue is empty";
            return 0;
        }
        int ans = data[firstindex];
        firstindex = ((firstindex + 1) % capacity);
        size--;
        if (size == 0) // not compulsary
        {
            firstindex = -1;
            nextindex = 0;
        }
        return ans;
    }
};

int main()
{
    QueueUsingArray s(5);
    s.enqueue(10);
    s.enqueue(20);
    s.enqueue(30);
    s.enqueue(40);
    s.enqueue(50);
    s.enqueue(60);
    cout << s.front();
    cout << s.dequeue();
    cout << s.dequeue();
    cout << s.dequeue();
    cout << s.getsize();
    cout << s.isEmpty();
    return 0;
}