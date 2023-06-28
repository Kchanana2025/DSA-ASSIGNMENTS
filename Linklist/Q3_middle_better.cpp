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
// WE ARE DOING THIS QUESTION IN A SINGLE ITERATION and we calculated middle initially by by doing 2 iterations

node *middle(node *head) // watch video of fraz(yt channel)
{
    node *slow = head; // walks at x speed
    node *fast = head; // walks at 2x speed
    // if fast reaches last node/NULL slow will be at middle node
    while (fast != NULL || fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{
    int i;
    node *head = takeinput();
    node *temp = middle(head);
    cout << temp->data;
    return 0;
}
