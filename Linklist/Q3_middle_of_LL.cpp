#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
    }
};
node *takeinput()
{

    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL;
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);

        if (head == NULL)

        {
            head = newnode;
            tail = newnode;
        }
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}
node *middle(node *head) // watch video of fraz(yt channel)
{
    node *temp = head;
    int len = 0;
    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    int mid = len / 2;
    temp = head;
    while (mid--) // jitna mid hai utni hi iterations krni hai head ko mid tak pahuchane ke lie
    {
        temp = temp->next;
    }
    return temp; // memory address of middle element
}

int main()
{
    int i;
    node *head = takeinput();
    node *temp = middle(head);
    cout << temp->data;
    return 0;
}
