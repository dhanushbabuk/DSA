/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };


*****************************************************************/

class Stack
{
    // Write your code here
    Node *head;
    int sz;

public:
    Stack()
    {
        // Write your code here
        head = nullptr;
        sz = 0;
    }

    int getSize()
    {
        // Write your code here
        return sz;
    }

    bool isEmpty()
    {
        // Write your code here
        return (head == nullptr);
    }

    void push(int data)
    {
        // Write your code here
        Node *temp = new Node(data);
        temp->next = head;
        head = temp;
        sz++;
    }

    void pop()
    {
        // Write your code here
        if (!isEmpty())
        {

            head = head->next;
            sz--;
        }
    }

    int getTop()
    {
        // Write your code here
        if (isEmpty())
            return -1;

        return (head->data);
    }
};