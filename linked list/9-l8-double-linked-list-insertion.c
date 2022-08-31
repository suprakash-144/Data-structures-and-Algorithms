#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *createlinkedlist(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    if (head == NULL)
    {
        ptr->prev = NULL;
        ptr->next = NULL;
        head = ptr;
        return head;
    }
    head->prev = ptr;
    ptr->next = head;
    head = ptr;
    head->prev = NULL;
    return head;
}
struct node *insert_at_index(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    struct node *q = head->next;
    int i = 0;
    while (i < index - 1)
    {
        p = p->next;
        q = q->next;
        i++;
    }
    ptr->prev = p;
    ptr->next = q;
    p->next = ptr;
    q->prev = ptr;
    return head;
};
struct node *insert_at_end(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->prev = p;
    ptr->next = NULL;
    return head;
}
void linkedlist_traversal(struct node *ptr)
{
    printf("\n Linked list: \n");
    while (ptr != NULL)
    {
        printf("Element :%d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    int n, data;
    printf("Enter the number of elemnts: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Element: ");
        scanf("%d", &data);
        head = createlinkedlist(head, data);
    }

    linkedlist_traversal(head);

    head = insert_at_index(head, 50, 3);
    linkedlist_traversal(head);

    return 0;
}
