// inflix to postfix
#include <iostream>
using namespace std;
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
    cin >> n;
    stack st(n); // stack of capacity=n
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
        }
    }
}

int main()
{

    return 0;
}