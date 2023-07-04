#define MAX 100
#include <iostream>
using namespace std;
class stackusingarray
{
public:
    int top;
    int arr[MAX];
    stackusingarray()
    {
        top = -1;
    }
    int size()
    {
        return top + 1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isfull()
    {
        return top == MAX - 1;
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "stack is empty";
            return INT_MIN;
        }
        else
        {
            return arr[top];
        }
    }
    void push(int element)
    {
        if (isfull())
        {
            cout << "overflow";
            return;
        }
        top++;
        arr[top] = element;
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow";
        }
        else
        {
            top--;
        }
    }
};
int main()
{
    stackusingarray s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.peek();
    s.pop();

    return 0;
}