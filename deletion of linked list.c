#include <stdio.h>


struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


struct Node* createNode(int value)
{
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}


void createList(int value)
{
    struct Node* newNode = createNode(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
}


void deleteFirst()
{
    if (head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }

    struct Node* temp = head;
    head = head->next;
    printf("Deleted first element: %d\n", temp->data);
    free(temp);
}


void deleteSpecified(int key)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;


    if (head->data == key)
    {
        head = head->next;
        printf("Deleted element: %d\n", temp->data);
        free(temp);
        return;
    }


    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element %d not found.\n", key);
        return;
    }

    prev->next = temp->next;
    printf("Deleted element: %d\n", temp->data);
    free(temp);
}


void deleteLast()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    if (head->next == NULL)
    {
        printf("Deleted last element: %d\n", head->data);
        free(head);
        head = NULL;
        return;
    }

    struct Node* temp = head;
    struct Node* prev = NULL;

    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    printf("Deleted last element: %d\n", temp->data);
    free(temp);
    prev->next = NULL;
}


void display()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    printf("Linked List: ");
    while (temp != NULL)
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


int main()
{
    int choice, value;

    while (1)
    {
        printf("\n--- Singly Linked List Menu ---\n");
        printf("1. Create (Insert at End)\n");
        printf("2. Delete First Element\n");
        printf("3. Delete Specified Element\n");
        printf("4. Delete Last Element\n");
        printf("5. Display List\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                createList(value);
                break;
            case 2:
                deleteFirst();
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &value);
                deleteSpecified(value);
                break;
            case 4:
                deleteLast();
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}
