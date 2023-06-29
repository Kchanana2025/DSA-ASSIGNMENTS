#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
    node(int data)
    { // contructor
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
    node *tail = NULL;
    while (data != -1)
    {
        node *newnode = new node(data);
        if (head == NULL)
        {
            head = newnode;
            tail = newnode;
        }
        else // agle node ka address pichle node mein daldo
        {
            tail->next = newnode;
            tail = tail->next; // OR tail=newnode;
        }

        cin >> data;
    }
    return head;
}
node *insertion_beg(node *head)
{
    // node* temp=head;
    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *newnode = new node(data);
    newnode->next = head;
    head = newnode;
    return head;
}
void insert_mid(node *head)
{
    int data;
    int position;
    cin >> position;
    cin >> data;
    node *temp = head;
    int i = 0;
    node *newnode = new node(data);
    while (i < position - 1) // dry run krke dekho smjh aa jayega
    {
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
}
void insert_end(node *head)
{
    int data;
    cin >> data;
    node *newnode = new node(data);

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    // confirm krlo ye// no point of updating tail we are using tail only in inputing link list aur wahan hm tail return kr ni skte-> therefore badmein hamien ek loop toh chalana hi padhega end of link list ko reach krne ke lie direct tail nai use kr paenge
    // head toh return krna hi padhega akele tail ka kya karoge isliye poora loop chalao
}
node *deletion_beg(node *head)
{
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
void deletion_mid(node *head)
{
    // indexes must not be 0 and end
    node *temp = head;
    int pos;
    cin >> pos;
    int j = 0;
    while (temp != NULL && j < pos - 1)
    {
        temp = temp->next;
        j++;
    }
    if (temp != NULL && temp->next != NULL) // it should not be last node because below we have written code for index/pos=0 to pos=n-2
    {
        node *a = temp->next;
        node *b = a->next;
        temp->next = b;
        delete a;
    }
}
void deletion_end(node *head)
{
    node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    // after end of loop temp is at second last node
    node *a = temp->next;
    if (a != NULL)
    {
        temp->next = a->next;
    }
    delete a;
    // no need to update tail,its not even there in memory it was deallocated with end of take input function
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
void search(node *head)
{
    int data;
    cin >> data;
    node *temp = head;
    int i = 0;
    while (temp != NULL)
    {
        if (temp->data == data)
        {
            cout << "element found";
            break;
        }
        i++;
        temp = temp->next;
    }
    cout << "position" << i;
}
int main()
{
    // variable and functions defined in public section of class are accessible in int main() but functions and variables defined outside class and outside main() are inaccessible in int main()
    int a;
    char ch;
    node *head = takeinput();
    do
    {
        cout << "ENTER CHOICE";
        cout << "1.Insertion at the beginning" << endl;
        cout << "2.Insertion in between." << endl;
        cout << "3. Insertion at end" << endl;
        cout << "4. deletion at beg" << endl;
        cout << "5. deletion at mid" << endl;
        cout << "6. deletion at end" << endl;
        cout << "8.Print the Link list" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            head = insertion_beg(head);
            break;
        case 2:
            insert_mid(head);
            break;
        case 3:
            insert_end(head);
            break;
        case 4:
            head = deletion_beg(head);
            break;
        case 5:
            deletion_mid(head);
            break;
        case 6:
            deletion_end(head);
            break;
        case 7:
            search(head);
            break;
        case 8:
            print(head);
            break;
        default:
            cout << "Wrong entered";
        }
        cout << "Do you wish to continue";
        cin >> ch;
    } while (ch != 'n');
    return 0;
}
