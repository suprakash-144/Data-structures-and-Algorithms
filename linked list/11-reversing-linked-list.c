#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *creat_list(struct node *head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    if (head == NULL)
    {
        temp->next = NULL;
        head = temp;
        return head;
    }
    temp->next = head;
    head = temp;
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
    struct node *temp;
    struct node *next = head->next;
    current->next = NULL;
    while (next != NULL)
    {
        temp = next->next;
        next->next = current;
        current = next;
        next = temp;
    }
    head = current;
    print(head);
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