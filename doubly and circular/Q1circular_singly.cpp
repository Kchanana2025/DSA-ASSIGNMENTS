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
        newnode->next = newnode;
        head = newnode;
        return head;
    }
    else
    {
        node *temp1 = head;
        while (temp1->next ! = head && temp->data != value)
        {
            temp1 = temp1->next;
        }
        if (temp1->next == head && temp1->data != value)
        {
            cout << "node is not present";
        }

        else // node agar last mein insert krni  hai yaa beechme ho jayegi iss code se
        {
            newnode->next = temp1->next;
            temp1->next = newnode;
        }
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
    node *temp1 = head;
    while (temp1->next != head)
    {
        temp1 = temp1->next;
    }
    if (temp1 == head) // ye sare edge cases while loop ke neeche hi likha kro smjhne mein aasani hoti hai like for eg agr temp1 hai hi head toh mtlb wo aage hi badha toh mtlb it is first node
    {                  // there is only one node
        head = NULL
    }
    else
    {
        node *a = head;
        head = head->next;
        temp1->next = head; // updated head
        delete a;
    }
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
        node *pre = head;
        node *temp1 = head;
        while (temp1->next != head)
        {
            pre = temp1;
            temp1 = temp1->next;
        }
        if (temp1 == head) // agar ek hi node present ho
        {
            head = NULL;
        }
        else // normal case
        {
            pre->next = temp1->next; // or pre->next=head;
            delete temp1;
        }
    }
}

node *delete_any_node(node *head, int value)
{
    if (head == NULL)
    {
        cout << "List is empty";
    }
    else
    {
        node *pre = head;
        node *temp = head;
        while (temp->next != head && temp->data != value) // hmne poori link list traverse kr li hai pr last node ki value check ni kri bus
        {
            pre = temp;
            temp = temp->next;
        }
        if (temp = head) // ek hi node hai agar toh{
        {
            delete_begin(temp);
        }
        if (temp->next == head && temp->data != value) // agar(if) upar wala loop last node pe aane ki vjah se terminate ho gya hai lekin uss node ka data bhi value ke equal nai hai toh mtlb node present nai hai
        {
            cout << "node is not present";
        }
        else // last node aur normally koi bhi node dono ke case aa gye (jiski value value se match hui hogi)
        {
            pre->next = temp->next;
            delete temp;
        }
    }
    return head;
}
void search(node *head, int value)
{
    if (head == NULL)
    {
        cout << "Link list is empty";
    }
    else
    {
        node *temp = head;
        int i = 0;
        while (temp->next != head && temp->data != value)
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
    if (head == NULL)
    {
        cout << "Link list is empty";
    }
    else
    {
        node *temp1 = head;
        while (temp1->next != head)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        temp->data << endl; // last node ka data
    }
}

int main()
{
    node *head = new node(20);
    print(head);
    return 0;
}