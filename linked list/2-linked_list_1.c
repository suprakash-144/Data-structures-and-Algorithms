#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
void linkedlist_traversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element :%d \n", ptr->data);
        ptr = ptr->next;
    }
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
    tail->next = NULL;

    linkedlist_traversal(head);
    return 0;
}
