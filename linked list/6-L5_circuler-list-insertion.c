#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlist_traversal(struct node *head)
{
    struct node *ptr;
    ptr = head;
    int i = 0;
    do
    {
        printf("Element at index %d :%d \n", i, ptr->data);
        ptr = ptr->next;
        i++;
    } while (ptr != head);
    printf("\n");
}
struct node *insert_at_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return ptr;
}
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = head;
    return head;
}
struct node *insert_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
struct node *insert_with_key(struct node *head, int data, int key)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;

    while (p->data != key)
    {
        p = p->next;
    }
    ptr->next = p->next;
    p->next = ptr;
    return head;
}
int main()
{
    struct node *head;
    struct node *second;
    struct node *tail;
    head = (struct node *)malloc(sizeof(struct node));
    second = (struct node *)malloc(sizeof(struct node));
    tail = (struct node *)malloc(sizeof(struct node));

    head->data = 15;
    head->next = second;
    second->data = 20;
    second->next = tail;
    tail->data = 35;
    tail->next = head;

    linkedlist_traversal(head);

    head = insert_at_first(head, 40);
    linkedlist_traversal(head);

    head = insert_at_end(head, 40);
    linkedlist_traversal(head);

    head = insert_at_index(head, 40, 2);
    linkedlist_traversal(head);

    head = insert_with_key(head, 40, 15);
    linkedlist_traversal(head);

    return 0;
}
