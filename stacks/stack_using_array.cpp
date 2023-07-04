#define MAX 100
#include <iostream>
#include <climits>
using namespace std;
class stack_using_array
{
    int arr[MAX];
    int top; // top index

public:
    stack_using_array(int total_size)
    {
        top = -1;             // later do it as 0
    }
    int size()
    {
        return top + 1;
    }
    bool isempty()
    {
        if (top == -1) // OR return top==-1;
            return true;
        else
            return false;
    }
    // insert element
    void push(int element)
    {
        if (top == capacity - 1)
        {
            cout << "STACK IS FULL" << endl;
            return;
        }
        top++;
        data[top] = element;
    }
    int pop()
    {
        if (isempty())
        {
            cout << "STACK IS EMPTY";
            return INT_MIN;
        }
        int temp = data[top];
        top--;
        return temp;
    }
    int top()
    {
        if (isempty())
        {
            cout << "STACK IS EMPTY";
            return INT_MIN;
        }
        return data[top];
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
