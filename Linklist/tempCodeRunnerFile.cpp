#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;

    node(int data)
    {
        this->data = data;
        next = NULL;
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
        else
        {
            tail->next = newnode;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}
void printIthNode(node *head, int i)
{ // i is basicallly index bro
    if (head == NULL)
    {
        return;
    }
    node *temp = head;
    for (int j = 0; j < i; j++)
    {
        if (temp != NULL)
            temp = temp->next;
    }
    if (temp != NULL)
        cout << temp->data;
}
// this method is so pyara
node *delete_occurances(node *head, int data)
{
    if (head == NULL)
        return;
    node *dummy = new node(-1);
    // dummy node bnai hai algo ko generlize krne ke lie dummy bnane se hoga ye ki ab aap sari nodes pe similarly
    //  work kr paoge waise hota kya h ki hum deletion ke waqt first node ko alag treat krte hain baki ki nodes ko alag treat krte hain
    dummy->next = head; // we joined dummy with head node
    node *tail = dummy; // ye pointer aage badhne ke lie hai
    while (tail != NULL && tail->next != NULL)
    {
        if (tail->next->data == data) // agr wo data hai toh delete krdo yaha aage isliye ni badh skte kyunki aage badne ke lie value ka unequal hona zrurui hai zaad kro kisi node ko delete krne ke lie hm uske peeche tak pointer laate the
        {
            node *temp = tail->next;
            tail->next = tail->next->next;
            delete temp;
        }
        // nai toh aage  badh jao
        tail = tail->next;
    }
    return dummy->next; 
}

int main()
{
    int i;
    int data;
    node *head = takeinput();
    cout << "ENTER THE VALUE OF data";
    cin >> data;
    delete_occurances(head, data);
    return 0;
}
