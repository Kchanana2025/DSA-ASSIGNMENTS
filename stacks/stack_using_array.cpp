#include <iostream>
#include <climits>
using namespace std;
class stack_using_array
{
    int *data;     // dyanmic stack
    int nextindex; // top index
    int capacity;  // total size

public:
    stack_using_array(int total_size)
    {
        data = new int[total_size]; // creating a dyanmic stack
        nextindex = -1;             // later do it as 0
        capacity = total_size;      // capacity is initial size and size is size at every time
    }
    int size()
    {
        return nextindex + 1;
    }
    bool isempty()
    {
        if (nextindex == -1) // OR return nextindex==-1;
            return true;
        else
            return false;
    }
    // insert element
    void push(int element)
    {
        if (nextindex == capacity - 1)
        {
            cout << "STACK IS FULL" << endl;
            return;
        }
        nextindex++;
        data[nextindex] = element;
    }
    int pop()
    {
        if (isempty())
        {
            cout << "STACK IS EMPTY";
            return INT_MIN;
        }
        int temp = data[nextindex];
        nextindex--;
        return temp;
    }
    int top()
    {
        if (isempty())
        {
            cout << "STACK IS EMPTY";
            return INT_MIN;
        }
        return data[nextindex];
    }
};
int main()
{
    stack_using_array s(4);
    s.push(10);
    s.push(10);
    s.push(30);
    s.push(40);
    s.push(50);
    cout << s.top() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.pop() << endl;
    cout << s.size() << endl;
    cout << s.isempty() << endl;
    return 0;
}
