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
    // head has to be moved along with new element
    // head->next = ptr;
    // ptr->prev = head;
    // head = ptr;
    // head->next = NULL;
    return head;
}
void linkedlist_traversal(struct node *ptr)
{
    printf("Linked list: \n");
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
    printf("ENter the number of elemnts: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Element: ");
        scanf("%d", &data);
        head = createlinkedlist(head, data);
    }

    linkedlist_traversal(head);
    return 0;
}
