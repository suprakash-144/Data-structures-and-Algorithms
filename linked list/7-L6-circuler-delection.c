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
    do
    {
        printf("Element :%d \n", ptr->data);
        ptr = ptr->next;
    } while (ptr != head);
    printf("\n");
}
struct node *delecte_at_first(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    struct node *p = head->next;
    head = head->next;
    while (p->next != ptr)
    {
        p = p->next;
    }
    p->next = head;
    free(ptr);
    return head;
}
struct node *delecte_at_end(struct node *head)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = head;
    struct node *p = head->next;
    // head = head->next;
    while (p->next != head)
    {
        ptr = ptr->next;
        p = p->next;
    }

    ptr->next = head;
    free(p);

    return head;
}
struct node *delecte_at_index(struct node *head, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    if (index == 0)
    {
        ptr = head;
        p = head->next;
        head = head->next;
        while (p->next != ptr)
        {
            p = p->next;
        }
        p->next = head;
        free(ptr);
        return head;
    }
    ptr = head;
    p = head->next;
    int i = 0;

    while (i != index - 1)
    {
        ptr = ptr->next;
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    free(p);
    return head;
}
struct node *delecte_wiht_key(struct node *head, int key)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p;
    ptr = head;
    if (key == head->data)
    {
        p = head->next;
        head = head->next;
        while (p->next != ptr)
        {
            p = p->next;
        }
        p->next = head;
        free(ptr);
        return head;
    }

    for (p = head->next; p->next != head; p = p->next)
    {
        if (p->data == key)
        {
            ptr->next = p->next;
            free(p);
            return head;
        }
        ptr = ptr->next;
    }

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

    head = delecte_at_first(head);
    linkedlist_traversal(head);

    head = delecte_at_end(head);
    linkedlist_traversal(head);

    head = delecte_at_index(head, 0);
    linkedlist_traversal(head);

    head = delecte_wiht_key(head, 20);
    linkedlist_traversal(head);
    return 0;
}
