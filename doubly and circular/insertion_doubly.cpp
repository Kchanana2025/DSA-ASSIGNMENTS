// kisi bhi node ko jiska NULL hone ka possibility ho wo ek baar check kr lia kro ->/. krwane se phle ki kahin wo NULL toh nai hai
// Node *head aise declarekia krow naki node* head
// phle normal code likha kro uske baad edge cases
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
    if (head != NULL) // agar 1 hi node hai toh head=NULL ho jayega
    {
        head->prev = NULL;
    }
    delete temp;
    return head;
}
void delete_end(node *head)
{
    node *temp = head;
    if (head == NULL)
    // 2 cheezien dekho 1)return type aur return krna hoga toh krdo nai toh mt kro 2)kya expectation hai swal ki wo expectation poori nai ho rhi hogi wo print krdo bss
    {
        cout << "Link list is empty";
    }

    else
    {

        while (temp->next != NULL)
        {
            previous = temp;
            temp = temp->next;
        }
        if (temp == head)
        {
            head = NULL;
            delete temp;
        }
        else
        {
            node *a = temp;
            temp->prev->next = NULL;
            delete a;
        }
    }
}
node *delete_any_node(node *head, int num, int value)
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        node *newnode = new node(num);
        node *temp = head;
        while (temp != NULL && temp->data != value)
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "Node is not present";
        }
        else if (temp == head)
        {
            head = head->next;
            delete temp;
        }
        if (temp->next == NULL)
        {
            temp->prev->next = NULL;
            delete temp;
        }
        else
        {
            temp->prev->next = temp->next;
            node *a = temp->next;
            a->prev = temp->prev;
        }
    }
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
    head = push_front(head);
    push_after(head, head->next);
    // push_end(head);
    print(head);
    return 0;
}