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
    ~node()
    {
        int value = this->data;
        if (this->next != NULL)
        {
            delete this->next;
            this->next = NULL;
        }
        cout << "memory free for data " << value << endl;
    }
};
void insertAtHead(node *&head, int d)
{
    node *temp = new node(d);
    temp->next = head;
    head = temp;
}
void insertAtTail(node *&tail, int d)
{
    node *temp = new node(d);
    tail->next = temp;
    tail = temp;
}
void insertAtPosition(node *tail, node *&head, int p, int d)
{
    if (p == 1)
    {
        insertAtHead(head, d);
        return;
    }
    node *temp = head;
    int c = 1;
    while (c < p)
    {
        temp = temp->next;
        c++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    node *newtemp = new node(d);
    newtemp->next = temp->next;
    temp->next = newtemp;
}
void deleteNode(int d, node *&head)
{
    if (d == 1)
    {
        node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    else
    {
        node *pr = NULL;
        node *curr = head;
        int cnt = 1;
        while (cnt < d)
        {
            pr = curr;
            curr = curr->next;
            cnt++;
        }
        pr->next = curr->next;
        curr->next = NULL;
        delete curr;
    }
}

void print(node *&head)
{
    node *temp = head;

    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *n1 = new node(10);
    cout << n1->data << endl;
    cout << n1->next << endl;
    node *head = n1;
    node *tail = n1;
    print(head);
    insertAtHead(head, 12);
    insertAtTail(tail, 14);
    insertAtPosition(tail, head, 3, 5);
    print(head);
    deleteNode(3, head);
    print(head);

    return 0;
}
