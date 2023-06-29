// inflix to postfix
#include <iostream>
using namespace std;
#include <iostream>
#include <math.h> //we used it for power function
using namespace std;
class stack_using_array
{
    int top;
    int capacity;
    int *head;

public:
    stack_using_array(int capacity) // an object of stack contains: an array ,a capacity and top
    {
        this->head = new int[capacity];
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
    int pop()
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
    int peek()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW";
            return '\0';
        }
        int temp = head[top];
        return temp;
    }
    bool empty()
    {
        if (top == -1)
        {
            return true;
        }
        return false;
    }
};
int postfix_evaluation(string s)
{
    stack_using_array st(10);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] > '0' && s[i] < '9')
        {
            st.push(s[i] - '0'); // for converting it into integer
        }
        else
        {
            int op2 = st.peek();
            st.pop();
            int op1 = st.peek();
            st.pop();
            // s[i] jo operator hai uska aur op1 aur op2 ka operation hoga
            switch (s[i])
            {
            case '+':
                st.push(op1 + op2);
                break;
            case '-':
                st.push(op1 - op2);
                break;
            case '*':
                st.push(op1 * op2);
                break;
            case '/':
                st.push(op1 / op2);
                break;
            case '^':
                st.push(pow(op1, op2));
                break;
            }
        }
    }
    return st.peek();
}

int main()
{
    cout << postfix_evaluation("46+2/5*7+");
    return 0;
}