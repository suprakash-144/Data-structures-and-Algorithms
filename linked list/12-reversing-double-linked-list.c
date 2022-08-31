#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};
struct node *creat_list(struct node *head, int data)
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
}
void print(struct node *head)
{
    struct node *ptr = head;
    printf("\nThe linked list is:\n");
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->next;
    }
    printf("\n");
}
void reverse(struct node *head)
{
    struct node *current = head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    head = current;
    struct node *ptr = head;
    printf("\nThe linked list is:\n");
    while (ptr != NULL)
    {
        printf("Element : %d \n", ptr->data);
        ptr = ptr->prev;
    }
    printf("\n");
}
int main()
{
    struct node *head = NULL;
    int n, data;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        printf("Element: ");
        scanf("%d", &data);
        head = creat_list(head, data);
    }

    print(head);
    reverse(head);
    return 0;
}