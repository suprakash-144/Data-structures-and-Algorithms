#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlist_traversal(struct node *ptr)
{
    int i = 0;
    while (ptr != NULL)
    {
        printf("Element at index %d :%d \n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    printf("\n");
}
struct node *insert_at_first(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}
struct node *insert_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;

    return head;
}
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    ptr->data = data;
    ptr->next = NULL;
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
    tail->next = NULL;

    linkedlist_traversal(head);
    head = insert_at_first(head, 56);
    linkedlist_traversal(head);
    head = insert_at_index(head, 150, 2);
    linkedlist_traversal(head);
    head = insert_at_end(head, 150);
    linkedlist_traversal(head);
    return 0;
}
