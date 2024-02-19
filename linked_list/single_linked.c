#include <stdio.h>
#include <stdlib.h>

struct node
{
    int info;
    struct node *next;
};
// struct node *head, *ptr;
struct node *getnode()
{
    struct node *newptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for the new node: ");
    scanf("%d", &(newptr->info));
    newptr->next = NULL;
    return newptr;
}
struct node *head = NULL;
void createList()
{
    char choice;
    struct node *last = NULL;
    do
    {

        struct node *newptr = getnode();
        if (head == NULL)
        {
            head = newptr;
        }
        else
        {
            last->next = newptr;
        }
        last = newptr;
        printf("Do you want to add more nodes(Y/N):");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');
}
void Insert_at_front()
{
    struct node *newptr = getnode();
    newptr->next = head;
    head = newptr;
}
void Insert_at_last()
{
    struct node *ptr = head;
    struct node *newptr = getnode();
    if (head == NULL)
    {
        head = newptr;
    }
    else
    {
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = newptr;
    }
}
void Insertion_at_anywhere()
{
    int key;
    printf("Enter the key after which data to be inserted: ");
    scanf("%d", &key);
    struct node *ptr = head;
    struct node *newptr = getnode();
    while (ptr->info != key && ptr != NULL)
    {
        ptr = ptr->next;
    }
    if (ptr != NULL)
    {
        newptr->next = ptr->next;
        ptr->next = newptr;
    }
    else
    {
        printf("Node with the key %d does not exist.", key);
    }
}

void delete_at_front()
{
    if (head != NULL)
    {

        struct node *ptr = head;
        head = head->next;
        free(ptr);
    }
    else
    {
        printf("Linked list is empty:\n ");
    }
}
void delete_at_last()
{
    struct node *ptr = head;
    struct node *prevptr;
    if (head == NULL)
    {
        printf("linked list is empty\n");
    }
    else
    {
        while (ptr->next != NULL)
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        prevptr->next = NULL;
        free(ptr);
    }
}

void Delete_at_anywhere()
{
    struct node *ptr = head;
    struct node *prevptr = NULL; // Initialize prevptr to NULL
    int key;
    printf("Enter the key after which data to be deleted: ");
    scanf("%d", &key);
    if (head == NULL)
    {
        printf("Linked list is empty:\n");
    }
    else
    {
        while (ptr != NULL && ptr->info != key) // Corrected condition order
        {
            prevptr = ptr;
            ptr = ptr->next;
        }
        if (ptr == NULL)
        {
            printf("Node with the key %d does not exist\n", key); // Moved outside the loop
        }
        else
        {
            if (prevptr == NULL) // Special case: Deleting the head node
            {
                head = ptr->next;
            }
            else
            {
                prevptr->next = ptr->next;
            }
            free(ptr);
        }
    }
}

void printdata()
{
    struct node *ptr = head;
    if (head == NULL)
    {
        printf("Linked list is empty:");
    }
    while (ptr != NULL)
    {
        printf("%d ", ptr->info);
        ptr = ptr->next;
    }
    printf("\n");
}
int main()
{
    int choice;
    printf("Inplementation of Singly linked list.\n");
    createList();
    while (1)
    {
        system("clear");
        printf("\n1.Insert_at_front\n"
               "2.print\n"
               "3.Insert_at_last\n"
               "4.Insert_at_anywhere\n"
               "5.Detele_at_front\n"
               "6.Delete_at_Last\n"
               "7.Delete_at_anywhere\n"
               "50.Exit\n>>");
        scanf(" %d", &choice);
        switch (choice)
        {
        case 1:
            Insert_at_front();
            break;
        case 2:
            printdata();
            break;
        case 3:
            Insert_at_last();
            break;
        case 4:
            Insertion_at_anywhere();
            break;
        case 5:
            delete_at_front();
            break;
        case 6:
            delete_at_last();
            break;
        case 7:
            Delete_at_anywhere();
            break;
        case 50:
            exit(0);
        }
        getchar();
        getchar();
    }
    return 0;
}