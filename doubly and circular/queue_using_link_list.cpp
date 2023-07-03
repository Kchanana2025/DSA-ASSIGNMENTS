class node
{
public:
    int data;
    node *next;
    node *prev;
    node(int data)
    {
        this->data = data;
        next = NULL;
        prev = NULL;
    }
};
class Queue_using_LL
{
public:
    node *front;
    node *rear;
    Queue_using_LL()
    {
        front = NULL;
        rear = NULL;
    }
    void enqueue(int element)
    {
        node *newnode = new node(element);
        if (front == NULL) // it is first node
        {
            newnode->next = newnode;
            newnode->prev = newnode;
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->next = newnode;
            newnode->prev = rear;
            rear = newnode;
            front->prev = newnode;
            newnode->next = front;
        }
    }

    void dequeue()
    {
        if (front == NULL)
        {
            cout << "queue empty";
            return;
        }
        else
        {
            if (front == rear) // only 1 node is present
            {
                front = NULL;
                rear = NULL;
            }
            node *a = front;
            rear->next = front->next;
            front = front->next;
            front->prev = rear;
            delete a;
        }
    }
    void print()
    {
        node *temp = front;
        cout << "front";
        while (temp != rear)
        {
            cout << temp->data;
            temp = temp->next;
        }
        cout << temp->data;
        cout << "rear";
    }
};