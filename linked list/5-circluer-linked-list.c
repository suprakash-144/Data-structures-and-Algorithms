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
    return 0;
}
