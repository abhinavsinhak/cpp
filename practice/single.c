#include <stdio.h>
#include<stdlib.h>
struct node {
    int data;
    struct node* next;
};
struct node* createNode(int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
int c = 0;
void insertAtHead(struct node *head, struct node *tail, int d)
{
    if (head == NULL)
    {
        struct node *temp = createNode(d);
        head = temp;
        tail = temp;
    }
    else
    {
        struct node *temp = createNode(d);
        temp->next = head;
        head = temp;
    }
    c++;
}
void insertAtTail(struct node *head,struct node *tail, int d)
{
    if (tail == NULL)
    {
        struct node *temp = createNode(d);
        head = temp;
        tail = temp;
    }
    else
    {
        struct node *temp = createNode(d);
        tail->next = temp;
        tail = temp;
    }
    c++;
}
void insertAtPosition(struct node *head,struct node *tail, int pos, int d)
{
    if (pos > c)
    {
        cout << "error!rewrite the position" << endl;
        return;
    }
    if (pos == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    else
    {
        struct node *temp = head;
        int cnt = 1;
        while (cnt < pos-1)
        {
            temp = temp->next;
            cnt++;
        }
        if (temp->next == NULL)
        {
            insertAtTail(head, tail, d);
            return;
        }
       struct node *newinst = createNode(d);
        newinst->next = temp->next;
        temp->next = newinst;
    }
    c++;
}
void deleteNode(struct node *head, int d)
{
    if (d == 1)
    {
        struct node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete (temp);
    }
    else
    {
        struct node *pr = NULL;
        struct node *curr = head;
        int cnt = 1;
        while (cnt < d)
        {
            pr = curr;
            curr = curr->next;
            cnt++;
        }
        pr->next = curr->next;
        curr->next = NULL;
        delete (curr);
    }
}
void print(node *head)
{
    struct node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl
         << endl;
}
int main()
{
    int c, d, pos;
    struct node *head = NULL;
    struct node *tail = NULL;
    while (1)
    {
        cout << "1.Insert At Head" << endl
             << "2.Insert At Tail" << endl
             << "3.Insert At Position" << endl
             << "4.Delete The Node" << endl
             << "5.Display" << endl
             << "6.Exit" << endl;

        cout << "enter your choice" << endl;
        cin >> c;
        switch (c)
        {
        case 1:
            cout << "enter the value" << endl;
            cin >> d;
            insertAtHead(head, tail, d);
            break;
        case 2:
            cout << "enter the value" << endl;
            cin >> d;
            insertAtTail(head, tail, d);
            break;
        case 3:
            cout << "enter the value" << endl;
            cin >> d;
            cout << "enter the position" << endl;
            cin >> pos;
            insertAtPosition(head, tail, pos, d);
            break;
        case 4:
            cout << "enter the position" << endl;
            cin >> pos;
            deleteNode(head, pos);
            break;
        case 5:
            print(head);
            break;
        case 6:
            exit(1);
            break;
        default:
            cout << "enter the valid choice: " 
                                 << endl;
            continue;
        }
    }
    return 0;
}