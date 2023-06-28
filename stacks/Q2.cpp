#include <cstring>
#include <iostream>
using namespace std;
class stack_using_array
{
    int top;
    int capacity;
    char *head;

public:
    stack_using_array(int capacity) // an object of stack contains: an array ,a capacity and top
    {
        this->head = new char[capacity];
        this->capacity = capacity;
        top = -1;
    }
    void push(int element)
    {
        if (top == capacity - 1)
        {
            cout << "stack is full";
            return;
        }
        top++;
        head[top] = element;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW";
            return '\0';
        }
        int temp = head[top];
        top--;
        return temp;
    }
};

int main()
{
    char str[] = "datastructure";

    int len = strlen(str);
    stack_using_array s(len);
    for (int i = 0; i < len; i++)
    {
        s.push(str[i]);
    }
    for (int i = 0; i < len; i++)
    {
        cout << s.pop();
    }
    return 0;
}