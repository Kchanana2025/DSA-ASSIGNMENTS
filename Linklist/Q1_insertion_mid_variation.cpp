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

void insert_mid_pos(node *head)
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
void insert_mid_after_value(node *head)
{
    int data_to_be_inserted;
    int value_after;
    cout << "Enter that value after which you wish to insert data";
    cin >> value_after;
    cout << "ENTER DATA";
    cin >> data_to_be_inserted;
    node *temp = head;
    node *newnode = new node(data_to_be_inserted);
    while (temp->data != value_after)
    {
        temp = temp->next;
    }
    // jo temp iss loop se bahar niklega ussi ke aage hmien apna data_to_be_inserted lgana hai
    newnode->next = temp->next;
    temp->next = newnode;
}
node *insert_mid_before_value(node *head)
{
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
        cout << "8.Print the Link list" << endl;
        cin >> a;
        switch (a)
        {
        case 1:
            insert_mid_pos(head);
            break;
        case 2:
            insert_mid_after_value(head);
            break;
        case 3:
            insert_mid_before_value(head);
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
