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
// shuru mein hi insert krte hai hmesha
node *insertion_beg(node *head, int data)
{
    node *newnode = new node(data);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    // node* temp=head;
    newnode->next = head;
    head = newnode;
    return head;
}

node *insert_mid(node *head, int value, int num) // value is value jiske baad insert krna hai and num is value jisko insert krna hai
{
    node *newnode = new node(num);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }
    node *temp = head;
    while (temp != NULL && temp->data != value)
    {
        temp = temp->next;
    }
    if (temp == NULL)
    {
        cout << "value to be deleted is not present";
        return head;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    return head;
}

node *insert_end(node *head, int num)
{

    node *newnode = new node(num);
    if (head == NULL)
    {
        head = newnode;
        return head;
    }

    node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newnode;
    return head;

    // confirm krlo ye// no point of updating tail we are using tail only in inputing link list aur wahan hm tail return kr ni skte-> therefore badmein hamien ek loop toh chalana hi padhega end of link list ko reach krne ke lie direct tail nai use kr paenge
    // head toh return krna hi padhega akele tail ka kya karoge isliye poora loop chalao
    // haan nai krte tail ke sath kuch bhi
}
node *deletion_beg(node *head)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY DELETION CANT TAKE PLACE";
        return head;
    }
    node *temp = head;
    head = head->next;
    delete temp;
    return head;
}
void deletion_mid(node *head, int num)
{
    if (head == NULL)
    {
        cout << "LIST IS EMPTY";
    }
    node *temp = head;
    if (temp->data == num) // hmien ye edge case isliye lgana padh rha hai because kisi bhi node ko delete krne ke lie hmien uske peeche khada hona zruri hai agr lekin wo first node hi hui toh uske peeche kaise khade hooge?
    {
        head = head->next;
        delete temp;
    }
    else
    {
        while (temp->next->data != num && temp != NULL) // it should not be last node because below we have written code for index/pos=0 to pos=n-2
        {
            temp = temp->next;
        }
        if (temp == NULL)
        {
            cout << "NODE IS NOT PRESENT";
        }
        else
        {
            node *a = temp->next;
            temp->next = NULL;
            delete a;
        }
    }
}
void deletion_end(node *head, int num)
{
    if (head == NULL)
        cout << "LINK LIST IS EMPTY";
    // return head;kyu krna hai return bhai?delete ho paya ho bhi head woi rahega nai ho paya toh bhi wohi rahega
    node *temp = head;
    if (temp->next == NULL) // only 1 node is present
    {
        head = NULL;
        delete temp;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        // after end of loop temp is at second last node
        node *a = temp->next;

        temp->next = NULL;
        delete a;
    }

    // no need to update tail,its not even there in memory it was deallocated with end of take input function
}
void deletion_end(node *head, int num)
{
    node *prev;
    if (head == NULL)
    {
        cout << "Link list is empty";
    }
    else
    {
        node *temp = head;
        while (temp->next != NULL)
        {
            prev = temp;
            temp = temp->next;
        }
        if (temp == head) // only 1 node is there in link list
        {
            head = NULL;
            delete temp;
        }
        else
        {
            prev->next = NULL;
            delete temp;
        }
    }
}
void print(node *head)
{
    node *temp = head;
    if (head == NULL)
        cout << "LINK LIST IS EMPTY";
    else
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}
void search(node *head, int num)
{
    int flag = 0;
    if (head == NULL)
        cout << "LINK LIST IS EMPTY";
    else
    {
        node *temp = head;
        int i = 0;
        while (temp != NULL)
        {
            if (temp->data == num)
            {
                cout << "element found";
                int flag = 1;
                break;
            }
            i++;
            temp = temp->next;
        }
        if (flag == 1)
        {
            cout << "element is presnt at position:" << i; // agar i print kr rhe ho toh i toh loop khtm hone ke baad bhi print ho hi jayega flag isliye lgaya hai kyunki flag=1 hoga tabhi element present hoga
        }
        else
        {
            cout << "element not present";
        }
    }
}
void search_another_method(node *head, int num)
{
    if (head == NULL)
        cout << "LINK LIST IS EMPTY";
    else
    {
        node *temp = head;
        int i = 0;
        while (temp != NULL && temp->data != num)
        {
            temp = temp->next;
            i++;
        }
        if (temp == NULL)
        {
            cout << "Element not present";
        }
        else
        {
            cout << "element present at position" << i;
        }
    }
}

int main()
{
    // variable and functions defined in public section of class are accessible in int main() but functions and variables defined outside class and outside main() are inaccessible in int main()
    int a;
    char ch;
    int num;   // value jisko insert krna hoe
    int value; // jiske baad insert krna padhe
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
            cin >> num;
            head = insertion_beg(head, num);
            break;
        case 2:
            cin >> num; // node after which you wish to insert value OR node which you wish to delete
            cin >> value;
            insert_mid(head, value, num);
            break;
        case 3:
            cin >> num;
            insert_end(head, num);
            break;
        case 4:
            head = deletion_beg(head, num);
            break;
        case 5:
            deletion_mid(head, num);
            break;
        case 6:
            deletion_end(head, num);
            break;
        case 7:
            search(head, num);
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
