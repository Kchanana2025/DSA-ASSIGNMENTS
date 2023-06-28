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
        }
        top++;
        head[top] = element;
    }
    char pop()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW";
        }
        int temp = head[top];
        top--;
        return temp;
    }
    char peek()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW";
            return '/0';
        }
        int temp = head[top];
        return temp;
    }
    bool isempty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
bool isvalid(string s)
{
    int n = s.size();
    stack_using_array st(n);
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
        {
            st.push(s[i]);
        }
        else
        {
            if (st.isempty())
                return false;

            char c = st.peek();
            st.pop();
            if ((s[i] == ')' && c == '(') ||
                (s[i] == ']' && c == '[') ||
                (s[i] == '}' && c == '{'))
            {
            }
            else
                return false;
        }
    }
    if (st.isempty())
        return true;

    return false;
}
main()
{
    string s = "){([])}";
    if (isvalid(s))
    {
        cout << "Valid String" << endl;
    }
    else
    {
        cout << "Invalid string";
    }

    return 0;
}