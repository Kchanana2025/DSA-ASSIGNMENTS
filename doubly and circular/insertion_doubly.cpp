#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    // pointer to the next node in DLL
    Node *next;
    // Pointer to previous node in DLL
    Node *prev;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};
//  insert a node at the front of the linked list
Node *push(Node *head)
{
    Node *newnode = new Node(10);
    // newnode->data = data; //NO NEED BECUASE IN CONTRUCTOR WE ARE ALREADY DOING THIS
    newnode->next = head;
    newnode->prev = NULL;
    if (head != NULL)
    {
        head->prev = newnode;
    }
    head = newnode;
    return head;
}
void print(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}
int main()
{
    Node *head = new Node(20);
    head = push(head);
    print(head);
    return 0;
}