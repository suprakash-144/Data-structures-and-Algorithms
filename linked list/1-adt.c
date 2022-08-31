#include <stdio.h>
#include <stdlib.h>

struct myarray
{
    int total_size;
    int used_size;
    int *ptr;
};

void create_array(struct myarray *A, int tot_size, int use_size)
{
    A->total_size = tot_size;
    A->used_size = use_size;
    A->ptr = (int *)malloc(tot_size * sizeof(int));
}

void take_input(struct myarray *A)
{
    int n;
    printf("\nEnter the elements of the array: ");
    for (int i = 0; i < A->used_size; i++)
    {
        scanf("%d", &n);
        (A->ptr)[i] = n;
    }
}

void show(struct myarray *A)
{

    printf("\nThe elements of the array are : ");
    for (int i = 0; i < A->used_size; i++)
    {
        printf("%d \t", (A->ptr)[i]);
    }
    printf("\n");
}

void insert(struct myarray *A, int key, int posiotin)
{
    int temp;
    for (int i = posiotin - 1; i <= A->used_size; i++)
    {
        temp = (A->ptr)[i];
        (A->ptr)[i] = key;
        key = temp;
    }
    A->used_size += 1;
}

void delete (struct myarray *A, int key)
{
    int temp;
    for (int j = 0; j < A->used_size; j++)
    {
        if (key == (A->ptr)[j])
        {   
            temp=j;
        }
    }
    for (int i = temp; i < A->used_size; i++)
    {
        (A->ptr)[i] = (A->ptr)[i + 1];
    }
    A->used_size -= 1;
}

void linear_serach(struct myarray *A, int key)
{

    int flag = 0;
    for (int i = 0; i < A->used_size; i++)
    {
        if (key == (A->ptr)[i])
        {
            flag = 1;
            printf("\nElement was found in the array at index : %d", i+1);
            break;
        }
        else
        {
            flag = 0;
        }
    }
    if (flag == 0)
    {
        printf("\nElement was not found in the array");
    }
}

void binary_search(struct myarray *A, int key)
{

    // used only when the array is sorted otherwise it does not work

    int mid, low, high;
    high = A->used_size;
    low = 0;
    mid = (high + low) / 2;
    while (mid >= 1)
    {
        if (key == (A->ptr)[mid])
        {
            printf("\nElement found at index: %d", mid - 1);
            break;
        }
        if (key > (A->ptr)[mid])
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}
int main()
{
    struct myarray a;
    int total, used, key, postion;
    printf("Enter the number of elememts : ");
    scanf("%d", &used);
    total = used * 2;
    create_array(&a, total, used);
    take_input(&a);
    show(&a);
    printf("\nEnter the value to be inserted: ");
    scanf("%d", &key);
    printf("Enter the postion to be inserted: ");
    scanf("%d", &postion);
    insert(&a, key, postion);
    show(&a);
    printf("\nEnter the element to be deleted : ");
    scanf("%d",&key);
    delete (&a,key);
    show(&a);
    printf("\nEnter the element to be Serched : ");
    scanf("%d", &key);
    linear_serach(&a, key);
    show(&a);
    return 0;
}
