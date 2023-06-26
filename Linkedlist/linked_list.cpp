#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node *next;
};



void linked_list_traversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->next;
    }
}




struct Node *insert_at_first(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    ptr->next = head;
    head = ptr;

    return head;
};



struct Node *insert_at_end(struct Node *head, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    struct Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }

    ptr->next = NULL;

    p->next = ptr;

    return head;
};



struct Node *insert_after_node(struct Node *head, struct Node *prev_node, int data)
{

    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));

    ptr->data = data;
    ptr->next = prev_node->next;
    prev_node->next = ptr;

    return head;
};



struct Node *insert_at_index(struct Node *head, int index, int data)
{

    if (index == 0)
    {
        head = insert_at_first(head, data);
        return head;
    }

    struct Node *p = head;
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
     ptr->data = data;

    int i = 0;

    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
   
    ptr->next = p->next;
    p->next = ptr;

    return head;
};



struct Node *delete_at_first(struct Node *head)
{
    struct Node *ptr = head;
    head = head->next;
    free(ptr);

    return head;
}



struct Node *delete_at_end(struct Node *head)
{
    struct Node *ptr = head;

    while(ptr->next->next != NULL){
        ptr=ptr->next;
    }

     ptr->next = NULL;

    struct Node *p = ptr->next;
    free(p);

    return head;
}



struct Node *delete_at_index(struct Node *head,int index)
{

    if(index==0){
        struct Node* newHead  = delete_at_first(head);
        return newHead;
    }

    struct Node*ptr = head;

    int i = 0;
    
    while(i != index-1){
        ptr = ptr->next;
        i++;
    }

    struct Node*p = ptr->next;
    ptr->next = p->next;
    free(p);

    return head;

}



struct Node* delete_element(struct Node*head,int element)
{
    struct Node*ptr = head;

    if( element == ptr->data ){
      head = delete_at_first(head);
      return head;
    }

    while(ptr->next->data != element && ptr->next != NULL){
        ptr=ptr->next;
    }

    struct Node*p = ptr->next;

    if(p->data == element){
        ptr->next = p->next;
        free(p);
    }

    return head;

}




int main()
{
    Node *head;
    Node *second;
    Node *third;
    Node *fourth;

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = second;

    second->data = 2;
    second->next = third;

    third->data = 3;
    third->next = fourth;

    fourth->data = 4;
    fourth->next = NULL;

    linked_list_traversal(head);
    // head= insert_at_first(head,55);
    // head = insert_at_index(head,0,90);
    // head = insert_at_end(head,1000);
    // head = insert_after_node(head,head,1000);

    // head = delete_at_first(head);
    // head = delete_at_end(head);
     head = delete_at_index(head,0);
    // head = delete_element(head,1);
    linked_list_traversal(head);

    return 0;
}





