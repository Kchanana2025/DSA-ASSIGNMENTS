// kisi bhi node ko jiska NULL hone ka possibility ho wo ek baar check kr lia kro ->/. krwane se phle ki kahin wo NULL toh nai hai
// Node *head aise declarekia krow naki node* head
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
node *insert_beg(node *head, int num) // num is value whose node we wish to insert
{
    node *newnode = new node(num); // we created a new node
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
    return head;
}
node *insert_end(node *head, int num)
{
    node *head = newnode node(num);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    node *temp = head;
    while (temp->next != NULL) // jab tak last node pr na aa jaye
    {
        temp = temp->next;
    }
    temp->next = newnode;
    newnode->prev = temp;
    return head;
}
node *insert_at_random_val(node *head, int num, int value)
{
}

Node *push_front(Node *head)
{
    int data;
    cin >> data;
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
void push_after(Node *head, Node *previous)
{
    int data;
    cin >> data;
    Node *newnode = new Node(data);
    if (previous != NULL)
    {
        newnode->next = previous->next;
        previous->next = newnode;
    }
    newnode->prev = previous;
    if (newnode->next != NULL)
        newnode->next->prev = newnode;
}
void push_before(Node *head, Node *front)
{
    if (front != NULL)
    {
        cout << "next node cant be NULL";
        return;
    }
    Node *newnode = new Node(10);

    newnode->next = front;

    newnode->prev = front->prev;
    front->prev = newnode;
    if (newnode->prev != NULL)
    {
        newnode->prev->next = newnode;
    }
    else
    {
        head = newnode;
    }
}
void_end

    void
    print(Node *head)
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
    head = push_front(head);
    push_after(head, head->next);
    // push_end(head);
    print(head);
    return 0;
}