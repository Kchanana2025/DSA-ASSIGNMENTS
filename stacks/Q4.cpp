// inflix to postfix
// data type pe dhyan do
// return nai kr rakha tha maine edge cases ke baad (stack is empty)/(stack is full ke baad)
// while ()loop mein peek ke baad pop krna bhool gayi
#include <iostream>
using namespace std;
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
    void push(char element)
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
        char temp = head[top];
        top--;
        return temp;
    }
    char peek()
    {
        if (top == -1)
        {
            cout << "STACK UNDERFLOW";
            return '\0';
        }
        char temp = head[top];
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
int prec(char c)
{
    if (c == '^')
    {
        return 3;
    }
    else if (c == '*' || c == '/')
    {
        return 2;
    }
    else if (c == '+' || c == '-')
    {
        return 1;
    }
    else // jab string mein opening bracket ajata hai
    {
        return -1;
    }
}
string infixtopostfix(string s)
{
    int n;
    cout << "ENTER SIZE";
    cin >> n;
    stack_using_array st(n); // stack of capacity=n
    string res;
    for (int i = 0; i < s.length(); i++)
    {
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) // operand
        {
            res += s[i];
        }
        else if (s[i] == '(')
        {
            st.push(s[i]);
        }
        else if (s[i] == ')')
        {
            while (!st.empty() && st.peek() != '(') // jab tak stack empty na ho jaye ya opening bracket na aa gaye pop krte raho
            {
                res += st.peek();
                st.pop();
            }
            if (!st.empty()) // agar upar wala while loop '(' opening bracket ki vhaj se khtm hua hai stack ke empty hone ki vjah se khtm nai hua toh pop krdo '(' isko kyunki abhi upar upar '(' yehi hoga
            {
                st.pop();
            }
        }
        else
        {
            while (!st.empty() && prec(st.peek()) >= prec(s[i]))
            {
                res += st.peek();
                st.pop();
            }
            st.push(s[i]); // precedence ab s[i] ki kum ho gayi hogi toh ab chlo push kr dete hain s[i]  ko stack mein
        }
    }
    while (!st.empty())
    {
        res += st.peek();
        st.pop();
    }
    return res;
}

int main()
{
    cout << infixtopostfix("(a-b/c)*(a/k-l)");
    return 0;
}