// Link list input krwake print krwana chah rhe hain hum
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
// Every function that is called without object must be defined outside class expect for static functions
node *takeinput() // is function ka kaam hai to create link list and to return head of that link list
{                 // arrays hm size puchte thee user se isme hum nai puchege because wohi toh avoid krna tha hamien isliye humne list list introduce kri
    // hm ya toh data enter krwake aise rakh skte hain ki jaise hi data -1 ho bss kro aur mat badhana LL ::Limitation ye hogi ki -1 ni daal skte
    // ya phir hum phli node enter krwake yes no puch skte hain user se ki aur krwana chahoge?

    int data;
    cout << "ENTER DATA";
    cin >> data;
    node *head = NULL; // initially null rakhte hai taki neeche jaake filter lga ske ki bhai agr head null hai toh head mein first node ka address daal do
    node *tail = NULL; // tail bhi use krege taki while loop ki vjah se hmari code ki complexity se n sqare se ghatke n ho jaye(tail na use krne pe nayi node daalne ke lie baar baar last node tak traverse krna padhta tha)
    while (data != -1)
    {
        node *newnode = new node(data); // isko dyanmically allocate kia hai bcz while loop khtm hone ke baad apki node deallocate na ho jaye
        if (head == NULL)               // newnode pointer stack memory mein hai wo deallocate ho jayega aur har naye node pe newnode hi point krega jsbki nayi node jo bani hai wo dyanmically bani hai toh wo heap memory mein hai
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
    if (head != NULL)
    {
        newnode->next = head;
    }
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
node *insert_end(node *head)
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
    // confirm this thing later// no point of updating tail we are using tail only in inputing link list aur wahan hm tail return kr ni skte-> therefore badmein hamien ek loop toh chalana hi padhega end of link list ko reach krne ke lie direct tail nai use kr paenge
}
node *deletion_beg(node *head)
{
    node *temp = head;
    temp = temp->next;
    delete head;
    head = temp;
}
node *deletion_mid(node *mid)
{
    node *temp = head;
    int data_to_del;
    cin >> data_to_del;
    while (temp != NULL)
    {
        if (temp->data == data_to_del)
        {
        }
    }
}
node *end(node *end)
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
            head = insertion_beg(head);
            break;
        case 2:
            insert_mid(head);
            break;
        case 3:
            insert_end(head);
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
