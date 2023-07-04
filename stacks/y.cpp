class node
{
    int data;
    node *next;

public:
    node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};
class stack_using_linklist
{
public:
    int top;
    stack_using_linklist()
    {
        top = NULL;
    }
    void push(int element)
    {
        node *newnode = new node(element);
        if (top == NULL)
        {
            top = newnode;
        }
        else
        {
            newnode->next = top;
            top = newnode;
        }
    }
    void pop()
    {
        if (isEmpty())
        {
            cout << "underflow";
        }
        else
        {
            node *a = top;
            cout << top->data;
            top = top->next;
            delete a;
        }
    }
    void display()
    {
        if (isempty())
        {
            cout << "empty";
        }
        else
        {
            node *temp = top;
            while (temp != NULL)
            {
                cout << temp->data;
                temp = temp->next;
            }
        }
    }
    bool isEmpty()
    {
        return top == NULL;
    }
};