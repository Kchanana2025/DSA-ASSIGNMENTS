#include <iostream>
using namespace std;
class Queueusingarray
{
    int *data;      // it is the pointer of array
    int firstIndex; // element will be deleted front this index
    int nextIndex;  // new element will be inserted at this index
    int size;       // no of actual elements in the array
    int capacity;

public:
    Queueusingarray(int s)
    {
        data = new int[s]; // creating a array of integers
        capacity = s;
        size = 0;
        firstIndex = -1;
        nextIndex = 0;
    }
    bool isEmpty()
    {
        return size == 0;
    }

    int getsize()
    {
        return size;
    }
    void enqueue(int element)
    {
        if (nextIndex == capacity - 1)
        // or if(size==capacity){
        //     cout<<"overflow"
        // }
        {
            cout << "overflow";
        }
        data[nextIndex] = element;
        if (isEmpty())
        {
            firstIndex = 0;
        }
        nextIndex = (nextIndex + 1) % capacity;
        size++;
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "underflow";
            return;
        }

        firstIndex = (firstIndex + 1) % capacity;
        size--;
    }
    int front()
    {
        if (isEmpty())
        {
            cout << "queue empty";
            return 0;
        }
        return data[firstIndex];
    }
};
int main()
{
    Queueusingarray Q(5);
    Q.enqueue(10); // class ke andar wale functions hmesha object bnake call hote hain
    Q.enqueue(20);
    Q.enqueue(30);
    Q.enqueue(40);
    Q.dequeue();
    cout << Q.front();
}