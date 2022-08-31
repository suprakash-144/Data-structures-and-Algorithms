#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *create_list(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        temp->prev = NULL;
        head = temp;
        return head;
    }
    head->prev = temp;
    temp->next = head;
    head = temp;
    head->prev = NULL;

    return head;
};
void print(struct node *head)
{
    struct node *ptr = head;
    printf("\nLinked list : \n");

    while (ptr != NULL)
    {
        printf("Elements are : %d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
struct node *delet_at_first(struct node *head)
{
    struct node *ptr = head;
    head = head->next;
    head->prev = NULL;
    free(ptr);
    return head;
}
struct node *delet_at_end(struct node *head)
{
    struct node *ptr = head;
    struct node *p = head->next;
    while (p->next != NULL)
    {
        p = p->next;
        ptr = ptr->next;
    }
    ptr->next = NULL;
    free(p);
    return head;
}
struct node *delet_at_index(struct node *head, int index)
{
    struct node *ptr = head;
    struct node *p = head->next;
    struct node *q;
    int i = 0;
    while (i != index - 2)
    {
        p = p->next;
        ptr = ptr->next;
        i++;
    }
    ptr->next = p->next;
    q = p;
    q = q->next;
    q->prev = ptr;
    free(p);
    return head;
}
int main()
{
    struct node *head = NULL;
    int n, i = 0, data;
    printf("Enter the number of elements : ");
    scanf("%d", &n);
    while (i < n)
    {
        printf("Element : ");
        scanf("%d", &data);
        head = create_list(head, data);
        i++;
    }
    print(head);

    head = delet_at_first(head);
    print(head);

    head = delet_at_end(head);
    print(head);

    head = delet_at_index(head, 3);
    print(head);

    return 0;
}