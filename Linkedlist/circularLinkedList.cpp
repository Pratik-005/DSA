#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int value)
    {
        data = value;
        next = NULL;
    }
};




void traversal(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    } while (ptr != head);
}



void insert_at_end(Node *head, int data)
{
    Node *ptr = new Node(data);

    if (head == NULL)
    {
        ptr->next = ptr;
        head = ptr;
        return;
    }

    Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    }
    ptr->next = head;
    p->next = ptr;
}



void insert_at_begin(Node *&head, int data)
{
    Node *ptr = new Node(data);

    if (head == NULL)
    {
        ptr->next = ptr;
        head = ptr;
        return;
    }

    Node *p = head;

    while (p->next != head)
    {
        p = p->next;
    };
    p->next = ptr;
    ptr->next = head;
    head = ptr;
}

void insert_at_index(Node *&head, int index, int data)
{

    Node *ptr = new Node(data);

    if (index == 0)
    {
        insert_at_begin(head, data);
        return;
    }

    Node *p = head;

    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
}


void delete_at_begin(Node *&head)
{
    Node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }

    Node *p = head;
    ptr->next = head->next;
    head = head->next;
    delete p;
}



void delete_at_end(Node *&head)
{
    Node *ptr = head;
    while (ptr->next->next != head)
    {
        ptr = ptr->next;
    }
    Node *p = ptr->next;
    ptr->next = head;
    delete p;
}



void delete_at_index(Node *&head, int index)
{
    if (index == 0)
    {
        delete_at_begin(head);
        return;
    }

    Node *ptr = head;

    int i = 0;
    while (i != index - 1)
    {
        ptr = ptr->next;
        i++;
    }

    Node *p = ptr->next;
    ptr->next = ptr->next->next;

    delete p;
}



void delete_element(Node *&head, int element)
{
    Node *ptr = head;

    if (element == ptr->data)
    {
        delete_at_begin(head);
        return;
    }

    while (ptr->next->data != element && ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    Node *p = ptr->next;
    if (p->data == element)
    {
        ptr->next = ptr->next->next;
        delete p;
    }
}



int main()
{

    Node *head = NULL;
    insert_at_begin(head, 34);
    insert_at_end(head, 84);
    // insert_at_end(head, 44);
    // insert_at_end(head, 98);
    // insert_at_end(head, 54);
    insert_at_index(head, 5, 99);
    delete_at_index(head, 2);
    delete_element(head, 34);

    traversal(head);
    return 0;
}
