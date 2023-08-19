#include <queue>
#include <iostream>
using namespace std;
void repeating_char(char str[])
{
    int char_count[26] = {0};
    queue<char> q;
    for (int i = 0; str[i] != '\0'; i++)
    {
        q.push(str[i]);
        char_count[str[i] - 'a']++;
        while (!q.empty())
        {
            if (char_count[q.front() - 'a'] > 1)
                q.pop();
            else
            {
                cout << q.front();
                break;
            }
        }
        if (q.empty())
        {
            cout << "-1";
        }
    }
}
int main()
{

    char str[] = "abcd";
    repeating_char(str);

    return 0;
}