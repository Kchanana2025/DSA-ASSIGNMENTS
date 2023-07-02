// insertion ke case mein hm baach gye thee tail se kyunki hmne starting of the link list mein hi agar inserion krdi toh bdia hai na
// lekin circular link list ke case mein hmien last node wala pointer chahie hi hoga taki last node ko first node se jod skien toh mtlb hamien hr baar traversal krna hoga kyunki head tail 2-2 cheezien toh hm return kr nai skte
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    // pointer to the next node in CLL(singly)
    node *next;

    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
node *takeinput()
{
    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL;
    node *tail = NULL; // tail bna lo ya hr baar traverse krlo last node tak par last node toh chahie hogi(temp->next!=head)
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
            newnode->next = head;
            tail->next = newnode;
            head = newnode;
        }

        cin >> data;
    }
    return head;
}
//  insert a node at the front of the linked list
node *insert_beg(node *head, int num) // num is value whose node we wish to insert
{
    node *newnode = new node(num);
    if (head == NULL)
    {
        head = newnode;
        newnode->next = head;
        return head;
    }
    newnode->next = head;
    node *temp1 = head;         // temp1 is similar to  tail
    while (temp1->next != head) // last node tak naa aa jaye
    {
        temp1 = temp1->next;
    }
    temp1->next = newnode;
    head = newnode; // ye aap while loop ke upar nai kr skte nai toh while loop infinite chl jaega because temp1->next mein kabhi newnode ayega hi nai
    // therefore  head ko last mein update krna chahie
}
node *insert_end(node *head, int num)
{
    node *newnode = new node(num);
    if (head == NULL)
    {

        newnode->next = newnode;
        head = newnode;
        return head;
    }
    node *temp1 = head;
    while (temp1->next != head)
    {
        temp1 = temp1->next;
    }
    newnode->next = head;
    temp1->next = newnode;
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
            cout << "node is not present";
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
void search(node *head, int num)
{
    if (head == NULL)
    {
        cout << "Link list is empty";
    }
    else
    {
        node *temp = head;
        int i = 0;
        while (temp->next != head && temp->data != num)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            cout << "node is not present in the link list";
        }
        else
        {
            cout << "node is present at index" << i;
        }
    }
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int main()
{
    node *head = new node(20);
    print(head);
    return 0;
}