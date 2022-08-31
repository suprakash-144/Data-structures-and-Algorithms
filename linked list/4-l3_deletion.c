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
struct node *deletion_at_first(struct node *head)
{
    struct node *ptr;
    // ptr is used to store the first node so that its memory can be releaseed
    ptr = head;
    // head is shifted to the next node so the firsr node can be erased
    head = head->next;
    free(ptr);
    return head;
}
struct node *deletion_at_index(struct node *head, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    // asign the node to be deleted to empty pointer
    ptr = p;
    // increase the index of the list
    p = p->next;
    // assign the index of the next node that will be deleted
    ptr->next = p->next;
    free(p);
    return head;
}
struct node *deletion_at_index2(struct node *head, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr = head->next;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    p->next = ptr->next;
    free(ptr);
    return head;
}

struct node *deletion_at_end(struct node *head)
{
    struct node *ptr;
    struct node *p;
    p = head;
    ptr = head->next;
    while (ptr->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    p->next = NULL;
    free(ptr);
    return head;
}
struct node *deletion_with_key(struct node *head, int key)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head;
    ptr = head->next;
    while (ptr->data != key && ptr->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    if (ptr->data == key)
    {
        p->next = ptr->next;
        free(ptr);
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
    tail->next = NULL;

    linkedlist_traversal(head);

    // head = deletion_at_first(head);

    // linkedlist_traversal(head);

    // head = deletion_at_index(head,1);

    // linkedlist_traversal(head);

    // head = deletion_at_index2(head,1);

    // linkedlist_traversal(head);

    // head = deletion_at_end(head);

    // linkedlist_traversal(head);

    head = deletion_with_key(head, 20);

    linkedlist_traversal(head);

    return 0;
}
