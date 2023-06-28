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
node *reverse_list(node *head) // watch fraz (yt) for understanding this code
{
    if (head == NULL)
        return NULL;
    node *prev = NULL;    // pointer before current ,prev is pointer jiska address hamien current ke next mein dalna hai
    node *curr = head;    // current pointer uss node ko point kr rha hai jiske next ko hamien reverse krna hai
    node *n = head->next; // required for moving forward
    while (curr != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = n;
        if (n != NULL)
            n = n->next;
    }
    return prev;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data;
        temp = temp->next;
    }
}

int main()
{
    int i;
    node *head = takeinput();
    head = reverse_list(head);
    print(head);
    return 0;
}
