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
        this->next = NULL;
    }
};
class stack
{
    node *head;
    int size;

public:
    stack()
    {
        head = NULL;
        size = 0;
    }
    // ye sare functions class ke andar bnn rhe hai because ye  objects ke through call honge
    int getsize()
    {
        return size;
    }
    bool isempty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
    void push(int element)
    { // hm shuru mein push krte hain Link list ke to decrease the time complexity of the code
        // we didnt check size of link list kyunki hmien ye pta hai ki link list ke nadar size ka constraint nai hota
        node *temp = new node(element);
        temp->next = head;
        head = temp;
        size++;
    }
    int pop()
    {
        node *temp;
        if (isempty())
        {
            return -1;
        }
        int num = head->data;
        temp = head;
        head = head->next;
        size--;
        delete temp;

        return num;
    }
};
int main()
{
    // data members and member functions defined in public are accessible in main isliye jo changes ho rhe hain head mein we are not returning
    stack S1;
    S1.push(10);
    S1.push(20);
    S1.push(30);
    S1.push(40);
    cout << S1.pop() << endl;

    cout << S1.pop() << endl;

    cout << S1.getsize() << endl;
    cout << S1.isempty() << endl;

    return 0;
}