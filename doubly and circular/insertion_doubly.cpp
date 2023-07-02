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
node *insert_after_given_value(node *head, int num, int value)
{
    node *newnode = new node(num);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    // hm jab if mein return kr dete hain toh neeche else likhne ki zarurat nai hoti kyunki ye understood hota hai ki
    //  wo else hai kyunki agar if execute hua toh return ho jayega aur else execute nai hoga aur agar if ki condition
    // false hogi tab toh if definately execute hoga
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
        cout << "element is not present";
    else if (temp->next == NULL)
    {
        temp->next = newnode;
        newnode->prev = temp;
    }
    else
    {
        newnode->next = temp->next;
        temp->next = newnode;
        temp->next->prev = newnode;
        newnode->prev = temp;
    }
    return head;
}

node *delete_begin(node *head)
{
    if (head == NULL)
    {
        cout << "link list is empty";
        return head;
    }
    node *temp = head;
    head = head->next;
    delete temp;
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
    head = push_front(head);
    push_after(head, head->next);
    // push_end(head);
    print(head);
    return 0;
}